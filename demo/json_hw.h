#ifndef __JSON_HW__
#define __JSON_HW__

#include "cJSON.h"

typedef struct json_hardware_io {
		cJSON *speed;
		cJSON *direction;
		cJSON *value;
		cJSON *IO;
		cJSON *IO_index;
		cJSON *status;
		cJSON *io_array;

		cJSON *io_node;
		int io_array_size;
		int io_array_index;
		int io_node_size;
		int io_node_index;
} json_hardware_io_t;


int json_hardware_decode_io(cJSON *jsonroot);

#endif