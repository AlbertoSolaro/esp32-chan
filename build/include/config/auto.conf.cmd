deps_config := \
	/home/Albert/esp/esp-idf/components/app_trace/Kconfig \
	/home/Albert/esp/esp-idf/components/aws_iot/Kconfig \
	/home/Albert/esp/esp-idf/components/bt/Kconfig \
	/home/Albert/esp/esp-idf/components/driver/Kconfig \
	/home/Albert/esp/esp-idf/components/esp32/Kconfig \
	/home/Albert/esp/esp-idf/components/esp_adc_cal/Kconfig \
	/home/Albert/esp/esp-idf/components/ethernet/Kconfig \
	/home/Albert/esp/esp-idf/components/fatfs/Kconfig \
	/home/Albert/esp/esp-idf/components/freertos/Kconfig \
	/home/Albert/esp/esp-idf/components/heap/Kconfig \
	/home/Albert/esp/esp-idf/components/libsodium/Kconfig \
	/home/Albert/esp/esp-idf/components/log/Kconfig \
	/home/Albert/esp/esp-idf/components/lwip/Kconfig \
	/home/Albert/esp/esp-idf/components/mbedtls/Kconfig \
	/home/Albert/esp/esp-idf/components/openssl/Kconfig \
	/home/Albert/esp/esp-idf/components/pthread/Kconfig \
	/home/Albert/esp/esp-idf/components/spi_flash/Kconfig \
	/home/Albert/esp/esp-idf/components/spiffs/Kconfig \
	/home/Albert/esp/esp-idf/components/tcpip_adapter/Kconfig \
	/home/Albert/esp/esp-idf/components/wear_levelling/Kconfig \
	/home/Albert/esp/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/Albert/esp/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/Albert/esp/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/Albert/esp/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)


$(deps_config): ;
