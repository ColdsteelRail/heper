ROOT_DIR = $(shell pwd)
LIB_DIR = $(ROOT_DIR)/library
TESTS_DIR = $(LIB_DIR)/tests
DEBUG_DIR = $(ROOT_DIR)/debug
BIN_DIR = $(DEBUG_DIR)/bin
OBJ_DIR = $(DEBUG_DIR)/obj

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
	$(LIB_DIR)/logging.o \
	$(LIB_DIR)/numlist.o \
	$(LIB_DIR)/common.o

ext-libs := -lm -lpthread -lrt

export ROOT_DIR \
	   IB_DIR \
	   TESTS_DIR \
	   lib \
	   DEBUG_DIR \
	   BIN_DIR \
	   OBJ_DIR \
	   CFLAGS \
	   ext-libs

$(LIB_DIR) : RUN
	make -C $@
RUN:

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
