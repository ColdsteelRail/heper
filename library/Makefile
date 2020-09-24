
# -std=c99 complie option of gcc is c89
# -Wall permit for gcc print warnning messages
# -Werror stop complie if warning occurs
# -g contain debug information in excutable program
# -D_GUN_SOURCE then you can use GUN entensions or non-standard functionality
CFLAGS = -std=c99 -Wall -Werror -O3 -g -D_GNU_SOURCE
LIB_DIR = $(shell pwd)
lib := 	\
	cpuinfo.o \
	version.o \
	percentiles.o \
	logging.o

export lib CFLAGS LIB_DIR


MAKE_SUBDIR := tests

make_lib : $(lib) $(MAKE_SUBDIR)
$(MAKE_SUBDIR) : RUN
	make -C $@	
RUN:

clean:
	rm -r *.o test_log *.log
