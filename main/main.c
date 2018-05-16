#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "connection_wifi.h"
#include "tcp_client.h"

// Main application
void app_main(){

	// Init wifi connection and wifi event handler
	connection_wifi();

	// Start tcp connection
	tcp_client();

	while(1) {
		vTaskDelay(1000 / portTICK_RATE_MS);
	}
}
