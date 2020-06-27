#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
TEXTFILEUTILS_OBJ_NAME=TextFileUtils
# component name
TEXTFILEUTILS_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGUTILS_COMPONENT_NAME)
# include and source paths - no need to change
TEXTFILEUTILS_OBJ_INCLUDE_PATH=$(TEXTFILEUTILS_OBJ_PATH)/include
TEXTFILEUTILS_OBJ_SRC_PATH=$(TEXTFILEUTILS_OBJ_PATH)/src

# used includes
TEXTFILEUTILS_INCLUDES_PATHS=$(sort	-I$(TEXTFILEUTILS_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

TEXTFILEUTILS_INCLUDES=$(sort	$(TEXTFILEUTILS_OBJ_INCLUDE_PATH)/$(TEXTFILEUTILS_OBJ_NAME).h \
									$(TEXTFILEUTILS_OBJ_PATH)/$(TEXTFILEUTILS_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
TEXTFILEUTILS_SRC=$(TEXTFILEUTILS_OBJ_SRC_PATH)/$(TEXTFILEUTILS_OBJ_NAME).c
TEXTFILEUTILS_OUTPUT_FOLDER=$(TEXTFILEUTILS_OBJ_PATH)/bin
TEXTFILEUTILS_OBJ=$(TEXTFILEUTILS_OUTPUT_FOLDER)/$(TEXTFILEUTILS_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(TEXTFILEUTILS_OBJ): $(TEXTFILEUTILS_INCLUDES) $(TEXTFILEUTILS_SRC)  $(TEXTFILEUTILS_OUTPUT_FOLDER) 
	$(CC) $(CFLAGS) -o $(TEXTFILEUTILS_OBJ) $(TEXTFILEUTILS_INCLUDES_PATHS) $(TEXTFILEUTILS_SRC)
