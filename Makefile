all : binaries


# -std=c99 complie option of gcc is c89
# -Wall permit for gcc print warnning messages
# -Werror stop complie if warning occurs
# -g contain debug information in excutable program
# -D_GUN_SOURCE then you can use GUN entensions or non-standard functionality
CFLAGS = -std=c99 -Wall -Werror -O3 -g -D_GNU_SOURCE

lib := 	\
	cpuinfo.o \
	version.o

test : test.o $(lib)
	$(CC) -o $@ $^

binaries : test


clean:
	rm -r *.o test
