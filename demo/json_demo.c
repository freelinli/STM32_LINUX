#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#define ERR_SUCCESS 0

int firmware_json_decode(cJSON *jsonroot)
{


	return ERR_SUCCESS;
}

int firmware_json_decode(cJSON *jsonroot)
{

	return ERR_SUCCESS;
}

/* Parse text to JSON, then render back to text, and print! */
void doit(char *text)
{
	char *out;cJSON *json;

	json = cJSON_Parse(text);
	if (!json) {
		printf("Error before: [%s]\n",cJSON_GetErrorPtr());
	} else	{
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
