#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
MEMORYUTILS_OBJ_NAME=MemoryUtils
# component name
MEMORYUTILS_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGUTILS_COMPONENT_NAME)
# include and source paths - no need to change
MEMORYUTILS_OBJ_INCLUDE_PATH=$(MEMORYUTILS_OBJ_PATH)/include
MEMORYUTILS_OBJ_SRC_PATH=$(MEMORYUTILS_OBJ_PATH)/src

# used includes
MEMORYUTILS_INCLUDES_PATHS=$(sort	-I$(MEMORYUTILS_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

MEMORYUTILS_INCLUDES=$(sort	$(MEMORYUTILS_OBJ_INCLUDE_PATH)/$(MEMORYUTILS_OBJ_NAME).h \
									$(MEMORYUTILS_OBJ_PATH)/$(MEMORYUTILS_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
MEMORYUTILS_SRC=$(MEMORYUTILS_OBJ_SRC_PATH)/$(MEMORYUTILS_OBJ_NAME).c
MEMORYUTILS_OUTPUT_FOLDER=$(MEMORYUTILS_OBJ_PATH)/bin
MEMORYUTILS_OBJ=$(MEMORYUTILS_OUTPUT_FOLDER)/$(MEMORYUTILS_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(MEMORYUTILS_OBJ): $(MEMORYUTILS_INCLUDES) $(MEMORYUTILS_SRC)  $(MEMORYUTILS_OUTPUT_FOLDER) 
	$(CC) $(CFLAGS) -o $(MEMORYUTILS_OBJ) $(MEMORYUTILS_INCLUDES_PATHS) $(MEMORYUTILS_SRC)
