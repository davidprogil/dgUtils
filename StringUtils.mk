#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
STRINGUTILS_OBJ_NAME=StringUtils
# component name
STRINGUTILS_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGUTILS_COMPONENT_NAME)
# include and source paths - no need to change
STRINGUTILS_OBJ_INCLUDE_PATH=$(STRINGUTILS_OBJ_PATH)/include
STRINGUTILS_OBJ_SRC_PATH=$(STRINGUTILS_OBJ_PATH)/src

# used includes
STRINGUTILS_INCLUDES_PATHS=$(sort	-I$(STRINGUTILS_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

STRINGUTILS_INCLUDES=$(sort	$(STRINGUTILS_OBJ_INCLUDE_PATH)/$(STRINGUTILS_OBJ_NAME).h \
									$(STRINGUTILS_OBJ_PATH)/$(STRINGUTILS_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
STRINGUTILS_SRC=$(STRINGUTILS_OBJ_SRC_PATH)/$(STRINGUTILS_OBJ_NAME).c
STRINGUTILS_OUTPUT_FOLDER=$(STRINGUTILS_OBJ_PATH)/bin
STRINGUTILS_OBJ=$(STRINGUTILS_OUTPUT_FOLDER)/$(STRINGUTILS_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(STRINGUTILS_OBJ): $(STRINGUTILS_INCLUDES) $(STRINGUTILS_SRC)  $(STRINGUTILS_OUTPUT_FOLDER) 
	$(CC) $(CFLAGS) -o $(STRINGUTILS_OBJ) $(STRINGUTILS_INCLUDES_PATHS) $(STRINGUTILS_SRC)
