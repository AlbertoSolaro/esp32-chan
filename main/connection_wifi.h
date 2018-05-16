#ifndef _CONNECTION_WIFI_H
#define _CONNECTION_WIFI_H

#define WIFI_SSID "Vodafone-A42271042"
#define WIFI_PASS ""

void connection_wifi();			// Init wifi and wifi event handler
void connection_wifi_wait();	// Wait BIT change on wifi event handler

#endif
