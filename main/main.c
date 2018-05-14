#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "connection_wifi.h"
#include "client_tcp.h"

// Main application
void app_main(){

	connection_wifi_main();
	client_tcp_start();

}
