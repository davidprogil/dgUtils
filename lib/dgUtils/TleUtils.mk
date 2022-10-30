#*******************************************************************************/
#* Copyright David Gil 1998-TODO                                               */
#* 								                                               */
#* davidgil@dgadv.com 			                                               */
#*******************************************************************************/

#------------------------------------------------------------------------------#
# object name
TLEUTILS_OBJ_NAME=TleUtils
# component name
TLEUTILS_OBJ_PATH=$(PROJECT_PATH)/lib/$(DGUTILS_COMPONENT_NAME)
# include and source paths - no need to change
TLEUTILS_OBJ_INCLUDE_PATH=$(TLEUTILS_OBJ_PATH)/include
TLEUTILS_OBJ_SRC_PATH=$(TLEUTILS_OBJ_PATH)/src

# used includes
TLEUTILS_INCLUDES_PATHS=$(sort	-I$(TLEUTILS_OBJ_INCLUDE_PATH) \
									$(COMMON_INCLUDES_PATHS) \
									$(SOMETHING_INCLUDES_PATHS))

TLEUTILS_INCLUDES=$(sort	$(TLEUTILS_OBJ_INCLUDE_PATH)/$(TLEUTILS_OBJ_NAME).h \
									$(TLEUTILS_OBJ_PATH)/$(TLEUTILS_OBJ_NAME).mk \
									$(COMMON_INCLUDES) \
									$(SOMETHING_INCLUDES))


#------------------------------------------------------------------------------#
# no need to change anything below this line
TLEUTILS_SRC=$(TLEUTILS_OBJ_SRC_PATH)/$(TLEUTILS_OBJ_NAME).c
TLEUTILS_OUTPUT_FOLDER=$(TLEUTILS_OBJ_PATH)/bin
TLEUTILS_OBJ=$(TLEUTILS_OUTPUT_FOLDER)/$(TLEUTILS_OBJ_NAME).o

#-SGP4-------------------------------------------------------------------------#
SGP4_OBJ_NAME=SGP4
SGP4_SRC=$(TLEUTILS_OBJ_SRC_PATH)/$(SGP4_OBJ_NAME).c
SGP4_OBJ=$(TLEUTILS_OUTPUT_FOLDER)/$(SGP4_OBJ_NAME).o
SGP4_INCLUDES=$(TLEUTILS_OBJ_INCLUDE_PATH)/$(SGP4_OBJ_NAME).h

$(SGP4_OBJ): $(SGP4_INCLUDES) $(SGP4_SRC)  $(TLEUTILS_OUTPUT_FOLDER) 
	$(CC) $(CFLAGS) -o $(SGP4_OBJ) $(TLEUTILS_INCLUDES_PATHS) $(SGP4_SRC)

#-TLE-------------------------------------------------------------------------#
TLE_OBJ_NAME=TLE
TLE_SRC=$(TLEUTILS_OBJ_SRC_PATH)/$(TLE_OBJ_NAME).c
TLE_OBJ=$(TLEUTILS_OUTPUT_FOLDER)/$(TLE_OBJ_NAME).o
TLE_INCLUDES=$(TLEUTILS_OBJ_INCLUDE_PATH)/$(TLE_OBJ_NAME).h

$(TLE_OBJ): $(TLE_INCLUDES) $(TLE_SRC)  $(TLEUTILS_OUTPUT_FOLDER) 
	$(CC) $(CFLAGS) -o $(TLE_OBJ) $(TLEUTILS_INCLUDES_PATHS) $(TLE_SRC)
#------------------------------------------------------------------------------#
# compile object
$(TLEUTILS_OBJ): $(SGP4_OBJ) $(TLE_OBJ) $(TLEUTILS_INCLUDES) $(TLEUTILS_SRC)  $(TLEUTILS_OUTPUT_FOLDER) 
	$(CC) $(CFLAGS) -o $(TLEUTILS_OBJ) $(TLEUTILS_INCLUDES_PATHS) $(TLEUTILS_SRC)
