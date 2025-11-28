CC 	   ?= gcc
CFLAGS ?= -Wall -Werror -nostdlib -nodefaultlibs -O3

OUTPUT := trsa.so

shared:
	$(CC) $(CFLAGS) -fpic -shared trsa.c -o $(OUTPUT)
