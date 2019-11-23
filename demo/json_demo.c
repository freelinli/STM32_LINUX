#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "json_demo.h"
#include "json_hw.h"
#include "log.h"
#define ERR_SUCCESS 0

#define TAG_FOR_FILE "JSON_DEMO"


int firmware_json_decode(cJSON *jsonroot)
{

	json_firmware_t json_firmware;
	int array_size = 0;

	json_firmware.device = cJSON_GetObjectItem(jsonroot, "device");
	json_firmware.software = cJSON_GetObjectItem(jsonroot, "software");
	json_firmware.hardware = cJSON_GetObjectItem(jsonroot, "hardware");
	json_firmware.authentication = cJSON_GetObjectItem(jsonroot, "authentication");

	if (json_firmware.device) {
			if(json_firmware.device->type == cJSON_Array) {
				array_size = cJSON_GetArraySize(json_firmware.device);
				if(array_size == 3) {
					LOG_DEBUG(TAG_FOR_FILE, "device name: %s %s %s\r\n", 
					cJSON_GetArrayItem(json_firmware.device, 0)->valuestring,
					cJSON_GetArrayItem(json_firmware.device, 1)->valuestring,
					cJSON_GetArrayItem(json_firmware.device, 2)->valuestring);
				}
			}
	}

	if (json_firmware.software) {
	
		json_firmware.software_sub_version = cJSON_GetObjectItem(json_firmware.software, "version");
		json_firmware.software_sub_date = cJSON_GetObjectItem(json_firmware.software, "date");
		json_firmware.software_sub_author = cJSON_GetObjectItem(json_firmware.software, "author");

		if (json_firmware.software_sub_version) {

			if(json_firmware.software_sub_version->type == cJSON_Array) {
				array_size = cJSON_GetArraySize(json_firmware.software_sub_version);
				if(array_size == 3) {
					LOG_DEBUG(TAG_FOR_FILE, "device software version: %d.%d.%d\r\n", 
					cJSON_GetArrayItem(json_firmware.software_sub_version, 0)->valueint,
					cJSON_GetArrayItem(json_firmware.software_sub_version, 1)->valueint,
					cJSON_GetArrayItem(json_firmware.software_sub_version, 2)->valueint);
				}
			}

		}
		if (json_firmware.software_sub_date) {
			if(json_firmware.software_sub_date->type == cJSON_Array) {
				array_size = cJSON_GetArraySize(json_firmware.software_sub_date);
				if(array_size == 3) {
					LOG_DEBUG(TAG_FOR_FILE, "device software date: %d.%d.%d\r\n", 
					cJSON_GetArrayItem(json_firmware.software_sub_date, 0)->valueint,
					cJSON_GetArrayItem(json_firmware.software_sub_date, 1)->valueint,
					cJSON_GetArrayItem(json_firmware.software_sub_date, 2)->valueint);
				}
			}
			
		}
		if (json_firmware.software_sub_author) {
			if(json_firmware.software_sub_author->type == cJSON_String) {
					LOG_DEBUG(TAG_FOR_FILE, "device software author: %s\r\n", 
					json_firmware.software_sub_author->valuestring);
			}		
		}
	}

	if (json_firmware.hardware) {

		json_firmware.hardware_sub_version = cJSON_GetObjectItem(json_firmware.hardware, "version");
		json_firmware.hardware_sub_date = cJSON_GetObjectItem(json_firmware.hardware, "date");
		json_firmware.hardware_sub_author = cJSON_GetObjectItem(json_firmware.hardware, "author");

		if (json_firmware.hardware_sub_version) {
			if(json_firmware.hardware_sub_version->type == cJSON_Array) {
				array_size = cJSON_GetArraySize(json_firmware.hardware_sub_version);
				if(array_size == 3) {
					LOG_DEBUG(TAG_FOR_FILE, "device software version: %d.%d.%d\r\n", 
					cJSON_GetArrayItem(json_firmware.hardware_sub_version, 0)->valueint,
					cJSON_GetArrayItem(json_firmware.hardware_sub_version, 1)->valueint,
					cJSON_GetArrayItem(json_firmware.hardware_sub_version, 2)->valueint);
				}
			}
		}
		if (json_firmware.hardware_sub_date) {
			if(json_firmware.hardware_sub_date->type == cJSON_Array) {
				array_size = cJSON_GetArraySize(json_firmware.software_sub_date);
				if(array_size == 3) {
					LOG_DEBUG(TAG_FOR_FILE, "device software date: %d.%d.%d\r\n", 
					cJSON_GetArrayItem(json_firmware.hardware_sub_date, 0)->valueint,
					cJSON_GetArrayItem(json_firmware.hardware_sub_date, 1)->valueint,
					cJSON_GetArrayItem(json_firmware.hardware_sub_date, 2)->valueint);
				}
			}
		}
		if (json_firmware.hardware_sub_author) {
			if(json_firmware.hardware_sub_author->type == cJSON_String) {
					LOG_DEBUG(TAG_FOR_FILE, "device software author: %s\r\n", 
					json_firmware.hardware_sub_author->valuestring);
			}		
		}
	}

	if (json_firmware.authentication) {
		LOG_DEBUG(TAG_FOR_FILE, "detect json_firmware.authentication in %s\r\n", __func__);
	}
	return ERR_SUCCESS;
}

int hardware_json_decode(cJSON *jsonroot)
{
	json_hardware_t  json_hardware;


	json_hardware.clock = cJSON_GetObjectItem(jsonroot, "clock");
	json_hardware.io = cJSON_GetObjectItem(jsonroot, "io");
	json_hardware.adc = cJSON_GetObjectItem(jsonroot, "adc");
	json_hardware.dac = cJSON_GetObjectItem(jsonroot, "dac");
	json_hardware.i2c = cJSON_GetObjectItem(jsonroot, "i2c");
	json_hardware.spi = cJSON_GetObjectItem(jsonroot, "spi");
	json_hardware.qspi = cJSON_GetObjectItem(jsonroot, "qspi");
	json_hardware.i2s = cJSON_GetObjectItem(jsonroot, "i2s");
	json_hardware.sdio = cJSON_GetObjectItem(jsonroot, "sdio");
	json_hardware.uart = cJSON_GetObjectItem(jsonroot, "uart");
	json_hardware.usb = cJSON_GetObjectItem(jsonroot, "usb");
	json_hardware.dma = cJSON_GetObjectItem(jsonroot, "dma");
	json_hardware.can = cJSON_GetObjectItem(jsonroot, "can");
	json_hardware.pwm = cJSON_GetObjectItem(jsonroot, "pwm");
	json_hardware.exit = cJSON_GetObjectItem(jsonroot, "exit");
	json_hardware.watchdog = cJSON_GetObjectItem(jsonroot, "watchdog");

	if (json_hardware.clock) {
	}
	if (json_hardware.io) {
		LOG_DEBUG(TAG_FOR_FILE, "detect json_hardware.io in %s\r\n", __func__);
		json_hardware_decode_io(json_hardware.io);
	}
	if (json_hardware.adc) {
	}
	if (json_hardware.dac) {
	}
	if (json_hardware.i2c) {
	}
	if (json_hardware.spi) {
	}
	if (json_hardware.qspi) {
	}
	if (json_hardware.i2s) {
	}
	if (json_hardware.sdio) {
	}
	if (json_hardware.uart) {
	}
	if (json_hardware.usb) {
	}
	if (json_hardware.dma) {
	}
	if (json_hardware.can) {
	}
	if (json_hardware.pwm) {
	}
	if (json_hardware.exit) {
	}
	if (json_hardware.watchdog) {
	}


	return ERR_SUCCESS;
}

int software_json_decode(cJSON *jsonroot)
{
	json_software_t json_software;

	return ERR_SUCCESS;
}

/* Parse text to JSON, then render back to text, and print! */
void doit(char *text)
{
	char *out;
	cJSON *json, *json_firmware, *json_hardware, *json_software;

	json = cJSON_Parse(text);
	if (!json) {
		printf("Error before: [%s]\n",cJSON_GetErrorPtr());
	} else	{
		out = cJSON_Print(json);
		printf("%s\n",out);
		free(out);
		
		json_firmware = cJSON_GetObjectItem(json, "firmware");
		if (json_firmware) {
			firmware_json_decode(json_firmware);
		}
		json_hardware = cJSON_GetObjectItem(json, "hardware");
		if (json_hardware) {
			hardware_json_decode(json_hardware);
		}
		json_software = cJSON_GetObjectItem(json, "software");
		if (json_software) {
			software_json_decode(json_software);
		}
	
		cJSON_Delete(json);
	}
}

/* Read a file, parse, render back, etc. */
void dofile(char *filename)
{
	FILE *f;long len;char *data;

	f = fopen(filename,"rb");
	fseek(f,0,SEEK_END);
	len = ftell(f);
	fseek(f,0,SEEK_SET);

	data = (char*)malloc(len+1);
	fread(data,1,len,f);
	fclose(f);

	doit(data);
	free(data);
}

int main (int argc, const char * argv[]) {

	xh_log_dst_disable(LOG_DST_FILE);
	LOG_DEBUG(TAG_FOR_FILE, "start do file in %s\r\n", __func__);
	/* Parse standard testfiles: */
	dofile("../json/hard-soft.json"); 

	return 0;
}
