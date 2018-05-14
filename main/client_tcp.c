#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"
#include "freertos/task.h"

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"

#include "lwip/netdb.h"
#include "lwip/sockets.h"

#include "client_tcp.h"

// HTTP request
static const char *REQUEST = "GET "CONFIG_RESOURCE" HTTP/1.1\n"
	"Host: "CONFIG_WEBSITE"\n"
	"User-Agent: ESP32\n"
	"\n";

void client_tcp_init(){
	const struct addrinfo hints = {
	  .ai_family = AF_INET,
	  .ai_socktype = SOCK_STREAM,
	};

	char recv_buf[100];

	struct addrinfo *res;
	// resolve the IP of the target website
	int result = getaddrinfo(CONFIG_WEBSITE, "80", &hints, &res);
	if((result != 0) || (res == NULL)) {
		printf("Unable to resolve IP for target website %s\n%s\n", CONFIG_WEBSITE,REQUEST);
		while(1) vTaskDelay(1000 / portTICK_RATE_MS);
	}
	printf("Target website's IP resolved\n");

	// create a new socket
	int s = socket(res->ai_family, res->ai_socktype, 0);
	if(s < 0) {
		printf("Unable to allocate a new socket\n");
		while(1) vTaskDelay(1000 / portTICK_RATE_MS);
	}
	printf("Socket allocated, id=%d\n", s);

	// connect to the specified server
	result = connect(s, res->ai_addr, res->ai_addrlen);
	if(result != 0) {
		printf("Unable to connect to the target website\n");
		close(s);
		while(1) vTaskDelay(1000 / portTICK_RATE_MS);
	}
	printf("Connected to the target website\n");

	// send the request
	result = write(s, REQUEST, strlen(REQUEST));
	if(result < 0) {
		printf("Unable to send the HTTP request\n");
		close(s);
		while(1) vTaskDelay(1000 / portTICK_RATE_MS);
	}
	printf("HTTP request sent\n");

	// print the response
	printf("HTTP response:\n");
	printf("--------------------------------------------------------------------------------\n");
	int r;
	do {
		bzero(recv_buf, sizeof(recv_buf));
		r = read(s, recv_buf, sizeof(recv_buf) - 1);
		for(int i = 0; i < r; i++) {
			putchar(recv_buf[i]);
		}
	} while(r > 0);
	printf("--------------------------------------------------------------------------------\n");

	close(s);
	printf("Socket closed\n");

	while(1) {
		vTaskDelay(1000 / portTICK_RATE_MS);
	}

}

void client_tcp_start(){
	xTaskCreate(&client_tcp_init, "client_tcp_init", 2048, NULL, 5, NULL);
}


