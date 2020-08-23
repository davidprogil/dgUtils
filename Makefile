#------------------------------------------------------------------------------#
# Copyright David Gil 1998-TODO                                                #
# 								                                               #
# davidgil@dgadv.com 			                                               #
#------------------------------------------------------------------------------#
PROJECT_PATH=$(shell pwd)
DGUTILS_OUTPUT_FOLDER=$(PROJECT_PATH)/bin
DGUTILS_LIB_NAME=dgUtils.so
DG_UTILS_LIB=$(DGUTILS_OUTPUT_FOLDER)/$(DGUTILS_LIB_NAME)

#--------------------------------------------------------------------------------
# project set-up
CC=gcc
CFLAGS=-Wall -c -fpic
LDFLAGS=-Wall -shared -o
AR=ar
TARGET=$(shell uname -m)
#--------------------------------------------------------------------------------
# project components
include dgUtils.mk

#------------------------------------------------------------------------------#							
# compile

$(DGUTILS_OUTPUT_FOLDER):
	mkdir -p $@
	
$(DG_UTILS_LIB): $(DGUTILS_OUTPUT_FOLDER) $(DGUTILS_COMPONENT_OBJ)
	$(CC) $(LDFLAGS) $@ $(DGUTILS_COMPONENT_OBJ)

compile: $(DG_UTILS_LIB)

clean:
	rm -rf $(DGUTILS_OUTPUT_FOLDER) $(DGUTILS_COMPONENT_OUTPUT_FOLDER)

all: compile

installSymbolic: $(DGUTILS_COMPONENT_INCLUDES) $(DG_UTILS_LIB)
	sudo mkdir -p /usr/local/include/dgl
	sudo ln -s -f $(DGUTILS_COMPONENT_INCLUDES) /usr/local/include/dgl
	sudo mkdir -p /usr/local/lib/dgl
	sudo ln -s -f $(DG_UTILS_LIB) /usr/local/lib/dgl/lib$(DGUTILS_LIB_NAME)

	