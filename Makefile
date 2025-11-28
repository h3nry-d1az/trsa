CC 	   ?= gcc
CFLAGS ?= -Wall -Werror -O3 -Iinclude

ENCRYPT := trsa.so
KEYGEN  := trsakg.so

trsa:
	$(CC) $(CFLAGS) -nostdlib -nodefaultlibs -fpic -shared\
		src/trsa.c -o $(ENCRYPT)

trsakg: trsa
	$(CC) $(CFLAGS) -fpic -shared -ltrsa\
		src/trsakg.c -o $(KEYGEN)