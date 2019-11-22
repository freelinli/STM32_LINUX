#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "json_demo.h"
#define ERR_SUCCESS 0



int firmware_json_decode(cJSON *jsonroot)
{

	json_firmware_t json_firmware;;

	json_firmware.device = cJSON_GetObjectItem(jsonroot, "device");
	json_firmware.software = cJSON_GetObjectItem(jsonroot, "software");
	json_firmware.hardware = cJSON_GetObjectItem(jsonroot, "hardware");
	json_firmware.authentication = cJSON_GetObjectItem(jsonroot, "authentication");

	if (json_firmware.device) {


	}
	if (json_firmware.software) {
	
		json_firmware.software_sub_version = cJSON_GetObjectItem(json_firmware.software, "version");
		json_firmware.software_sub_date = cJSON_GetObjectItem(json_firmware.software, "date");
		json_firmware.software_sub_author = cJSON_GetObjectItem(json_firmware.software, "author");

		if (json_firmware.software_sub_version) {


		}
		if (json_firmware.software_sub_date) {

			
		}
		if (json_firmware.software_sub_author) {

			
		}
	}

	if (json_firmware.hardware) {

		json_firmware.hardware_sub_version = cJSON_GetObjectItem(json_firmware.hardware, "version");
		json_firmware.hardware_sub_date = cJSON_GetObjectItem(json_firmware.hardware, "date");
		json_firmware.hardware_sub_author = cJSON_GetObjectItem(json_firmware.hardware, "author");

		if (json_firmware.hardware_sub_version) {


		}
		if (json_firmware.hardware_sub_date) {

			
		}
		if (json_firmware.hardware_sub_author) {

			
		}
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
		out = cJSON_Print(json);
		cJSON_Delete(json);
		printf("%s\n",out);
		free(out);
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

	/* Parse standard testfiles: */
	dofile("../json/hard-soft.json"); 

	return 0;
}
