CC=gcc
RM=rm -f
CORE=3
PWD=$(shell pwd)

C_SRC=$(shell find ./ -name '*.c')
C_OB49J=$(C_SRC:%.c=%.o)

INCFLAGS=-I ../user


all:cjson

$(C_OBJ):%.o:%.c
	$(CC) -c $^ -E $@

cjson: ../user/cJSON.c json_demo.c 
	$(CC) $^ $(INCFLAGS) -o $@ -lm -g 

test:
	echo "$(C_SRC)"
clean:
	$(RM) cjson *~
.PHONY:
	all clean
