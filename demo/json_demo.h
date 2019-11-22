#ifndef __JSON_DEMO__
#define __JSON_DEMO__

#include "hw_interface.h"

#define HW_INTERFACE_GPIO hw_interface_gpio_init


	typedef struct json_firmware {
		cJSON *device;
		cJSON *software;
		cJSON *software_sub_version;
		cJSON *software_sub_date;
		cJSON *software_sub_author;
		cJSON *hardware;
		cJSON *hardware_sub_version;
		cJSON *hardware_sub_date;
		cJSON *hardware_sub_author;
		cJSON *authentication;
	} json_firmware_t;

	typedef struct json_hardware {
		cJSON *clock;
		cJSON *io;
		cJSON *adc;
		cJSON *dac;
		cJSON *i2c;
		cJSON *spi;
		cJSON *qspi;
		cJSON *i2s;
		cJSON *sdio;
		cJSON *uart;
		cJSON *usb;
		cJSON *dma;
		cJSON *can;
		cJSON *pwm;
		cJSON *exit;
		cJSON *watchdog;
	} json_hardware_t;

	typedef struct json_software {
		cJSON *globaldata;
		cJSON *func;
		cJSON *main;
	
	} json_software_t;


#endif
