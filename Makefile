# .PHONY:clean all
# CC = gcc

# ROOT_DIR=$(shell pwd)
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

MAKE_SUBDIR := library
MAKE_SUBDIR : RUN
	make -C $@	
RUN: