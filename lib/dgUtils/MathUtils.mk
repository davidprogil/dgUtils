#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
MATHUTILS_OBJ_NAME=MathUtils
# component name
MATHUTILS_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGUTILS_COMPONENT_NAME)
# include and source paths - no need to change
MATHUTILS_OBJ_INCLUDE_PATH=$(MATHUTILS_OBJ_PATH)/include
MATHUTILS_OBJ_SRC_PATH=$(MATHUTILS_OBJ_PATH)/src

# used includes
MATHUTILS_INCLUDES_PATHS=$(sort	-I$(MATHUTILS_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

MATHUTILS_INCLUDES=$(sort	$(MATHUTILS_OBJ_INCLUDE_PATH)/$(MATHUTILS_OBJ_NAME).h \
									$(MATHUTILS_OBJ_PATH)/$(MATHUTILS_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
MATHUTILS_SRC=$(MATHUTILS_OBJ_SRC_PATH)/$(MATHUTILS_OBJ_NAME).c
MATHUTILS_OUTPUT_FOLDER=$(MATHUTILS_OBJ_PATH)/bin
MATHUTILS_OBJ=$(MATHUTILS_OUTPUT_FOLDER)/$(MATHUTILS_OBJ_NAME).o

#------------------------------------------------------------------------------#
# compile object
$(MATHUTILS_OBJ): $(MATHUTILS_INCLUDES) $(MATHUTILS_SRC)  $(MATHUTILS_OUTPUT_FOLDER) 
	$(CC) $(CFLAGS) -o $(MATHUTILS_OBJ) $(MATHUTILS_INCLUDES_PATHS) $(MATHUTILS_SRC)
