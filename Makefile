CC 	   ?= gcc
CFLAGS ?= -Wall -Werror -O3 -Iinclude

TRSADIR := .
TESTDIR := .
ENCRYPT := trsa.so
KEYGEN  := trsakg.so

trsa:
	$(CC) $(CFLAGS) -nostdlib -nodefaultlibs -fpic -shared\
		src/trsa.c -o $(TRSADIR)/$(ENCRYPT)

trsakg: trsa
	$(CC) $(CFLAGS) -fpic -shared -L$(TRSADIR) -ltrsa\
		src/trsakg.c -o $(TRSADIR)/$(KEYGEN)

test: test_math test_keygen

test_math: trsa
	$(CC) $(CFLAGS) -L$(TRSADIR) -ltrsa\
		tests/test_math.c -o $(TESTDIR)/test_math
	./$(TESTDIR)/test_math

test_keygen: trsa trsakg
	$(CC) $(CFLAGS) -L$(TRSADIR) -ltrsa -ltrsakg\
		tests/test_keygen.c -o $(TESTDIR)/test_keygen
	./$(TESTDIR)/test_keygen

docs:
	doxygen ./Doxyfile