ROOT_DIR = $(shell pwd)
LIB_DIR = $(ROOT_DIR)/library
TESTS_DIR = $(LIB_DIR)/tests
BIN_DIR = $(ROOT_DIR)/debug/bin
OBJ_DIR = $(ROOT_DIR)/debug/obj

CFLAGS = -std=c99 -Wall -Werror -O3 -g -D_GNU_SOURCE
# -std=c99 complie option of gcc is c89
# -Wall permit for gcc print warnning messages
# -Werror stop complie if warning occurs
# -g contain debug information in excutable program
# -D_GUN_SOURCE then you can use GUN entensions or non-standard functionality

lib := 	\
	$(LIB_DIR)/cpuinfo.o \
	$(LIB_DIR)/version.o \
	$(LIB_DIR)/percentiles.o \
	$(LIB_DIR)/logging.o

export ROOT_DIR \
	   IB_DIR \
	   TESTS_DI \
	   lib \
	   BIN_DIR \
	   OBJ_DIR \
	   CFLAGS

$(LIB_DIR) : RUN
	make -C $@
RUN:

clean:
	rm -rf $(TESTS_DIR)/*.o \
	       $(TESTS_DIR)/*.log \
	       $(TESTS_DIR)/test_log \
	       $(LIB_DIR)/*.o
