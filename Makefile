# .PHONY:clean all
# CC = gcc

#ROOT_DIR=$(shell pwd)
# OBJ_DIR=$(ROOT_DIR)/debug/obj
# BIN_DIR=$(ROOT_DIR)/debug/bin
# OBJ := 	\
# 	cpuinfo.o \
# 	version.o \
# 	percentiles.o \
# 	logging.o
# SUB_DIR := library
# # test
# BIN := test_log

# # compile options
# CFLAGS = -std=c99 -Wall -Werror -O3 -g -D_GNU_SOURCE

# export CC ROOT_DIR OBJ_DIR BIN_DIR OBJ BIN

# all : CHECKDIR $(SUB_DIR)
# CHECKDIR :
# 	mkdir -p $(SUB_DIR) $(BIN_DIR)

# $(SUB_DIR) : RUN
# 	make -C $@

# RUN:
ROOT_DIR = $(shell pwd)
LIB_DIR = $(ROOT_DIR)/library
TESTS_DIR= $(LIB_DIR)/tests

CFLAGS = -std=c99 -Wall -Werror -O3 -g -D_GNU_SOURCE
# -std=c99 complie option of gcc is c89
# -Wall permit for gcc print warnning messages
# -Werror stop complie if warning occurs
# -g contain debug information in excutable program
# -D_GUN_SOURCE then you can use GUN entensions or non-standard functionality

lib := 	\
	cpuinfo.o \
	version.o \
	percentiles.o \
	logging.o

export ROOT_DIR LIB_DIR TEST_DIR lib CFLAGS

$(LIB_DIR) : RUN
	make -C $@
RUN: