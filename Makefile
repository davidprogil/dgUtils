#------------------------------------------------------------------------------#
# Copyright David Gil 1998-TODO                                                #
# 								                                               #
# davidgil@dgadv.com 			                                               #
#------------------------------------------------------------------------------#
PROJECT_PATH=$(shell pwd)
DGUTILS_OUTPUT_FOLDER=$(PROJECT_PATH)/bin
DG_UTILS_LIB=$(DGUTILS_OUTPUT_FOLDER)/dgUtils.sa

#--------------------------------------------------------------------------------
# project set-up
CC=gcc
CFLAGS=-Wall -c 
LDFLAGS=-Wall
AR=ar

#--------------------------------------------------------------------------------
# project components
include dgUtils.mk

#------------------------------------------------------------------------------#							
# compile

$(DGUTILS_OUTPUT_FOLDER):
	mkdir -p $@
	
$(DG_UTILS_LIB): $(DGUTILS_OUTPUT_FOLDER) $(DGUTILS_COMPONENT_OBJ)
	$(AR) rcs $@ $(DGUTILS_COMPONENT_OBJ)

compile: $(DG_UTILS_LIB)

clean:
	rm -rf $(DGUTILS_OUTPUT_FOLDER) $(DGUTILS_COMPONENT_OUTPUT_FOLDER)

all: compile
	