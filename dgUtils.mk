#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

DGUTILS_COMPONENT_NAME=dgUtils
DGUTILS_COMPONENT_FOLDER=$(PROJECT_PATH)/lib/dgUtils
DGUTILS_COMPONENT_OUTPUT_FOLDER=$(DGUTILS_COMPONENT_FOLDER)/bin

$(DGUTILS_COMPONENT_OUTPUT_FOLDER):
	mkdir -p $@

#objects includes -----------------
include $(DGUTILS_COMPONENT_FOLDER)/MemoryUtils.mk
include $(DGUTILS_COMPONENT_FOLDER)/StringUtils.mk
include $(DGUTILS_COMPONENT_FOLDER)/MathUtils.mk
include $(DGUTILS_COMPONENT_FOLDER)/TextFileUtils.mk

DGUTILS_COMPONENT_INCLUDES_PATHS= \
						$(MEMORYUTILS_INCLUDES_PATHS) \
						$(STRINGUTILS_INCLUDES_PATHS) \
						$(MATHUTILS_INCLUDES_PATHS) \
						$(TEXTFILEUTILS_INCLUDES_PATHS) \


DGUTILS_COMPONENT_INCLUDES=	$(DGUTILS_COMPONENT_FOLDER)/$(DGUTILS_COMPONENT_NAME).mk \
						$(MEMORYUTILS_INCLUDES) \
						$(STRINGUTILS_INCLUDES) \
						$(MATHUTILS_INCLUDES) \
						$(TEXTFILEUTILS_INCLUDES) \


DGUTILS_COMPONENT_OBJ= \
						$(MEMORYUTILS_OBJ) \
						$(STRINGUTILS_OBJ) \
						$(MATHUTILS_OBJ) \
						$(TEXTFILEUTILS_OBJ) \

