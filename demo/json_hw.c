
#include <stdio.h>
#include "json_hw.h"
#include <stdlib.h>
#include <string.h>
#define DEBUG_STRING 0

int json_hardware_decode_io(cJSON *jsonroot)
{
	int array_size = 0, array_index = 0;
	char *debug_out;
	char oneline_code[128];
	json_hardware_io_t io;
	if(jsonroot->type != cJSON_Array) 
		return -1;

	FILE *file;

	file = fopen("../user/bsp_led.c","rw+");
	if (file == NULL) {
		printf("fopen error \r\n");
		return -1;
	}
	fseek(file, 0, SEEK_END);
	
	fputs("void SysInitIndictor(void)\r\n", file);
	fputs("{\r\n", file);


	array_size = cJSON_GetArraySize(jsonroot);
	for (array_index = 0; array_index < array_size; array_index++) {
		io.io_array = cJSON_GetArrayItem(jsonroot, array_index);
		if (io.io_array) {
			#if DEBUG_STRING == 1
			debug_out  = cJSON_Print(io.io_array);
			printf("%s\n",debug_out);
			free(debug_out);
			#endif
			io.status = cJSON_GetObjectItem(io.io_array, "status");
			
			if (io.status == NULL) 
				continue;
			if (strlen(io.status->valuestring) != 4 && memcmp("okay", io.status->valuestring, 4))
				continue;

			io.speed = cJSON_GetObjectItem(io.io_array, "speed");
			io.direction = cJSON_GetObjectItem(io.io_array, "direction");
			io.value = cJSON_GetObjectItem(io.io_array, "value");
			io.IO = cJSON_GetObjectItem(io.io_array, "IO");

			if (io.speed) {
				printf("io speed %s\r\n", io.speed->valuestring);
			}
			if (io.direction) {
				printf("io direction %s\r\n", io.direction->valuestring);
			}
			if (io.value) {
				printf("io value %s\r\n", io.value->valuestring);
			}
			if (io.IO) {

				for (io.io_array_index = 0; io.io_array_index < io.io_array_size; io.io_array_index++) {
					io.IO_index = cJSON_GetArrayItem(io.IO, io.io_array_index);
					if (io.IO_index) {
						io.io_node_size = cJSON_GetArraySize(io.IO_index);
						for (io.io_node_index = 0; io.io_node_index < io.io_node_size; io.io_node_index ++) {
							io.io_node = cJSON_GetArrayItem(io.IO_index, io.io_node_index);
							printf("io name:%s value:%s\r\n", io.io_node->string, io.io_node->valuestring);

							sprintf(oneline_code, "\tGPIO_Config(%s, RCC_APB2Periph_%s, GPIO_Pin_%s, %s, GPIO_Speed_%sHz, %s);\r\n",\
							io.io_node->string, io.io_node->string, io.io_node->valuestring,\
							memcmp(io.direction->valuestring, "out", 3) ?  "GPIO_Mode_IN_FLOATING" : "GPIO_Mode_Out_PP",\
							io.speed->valuestring, io.value->valuestring);
							fputs(oneline_code, file);
							printf("oneline_code:\r\n%s\r\n", oneline_code);

						}
						
					}

				}
				
			}
		}
	}
	fputs("}\r\n", file);
	fclose(file);

}