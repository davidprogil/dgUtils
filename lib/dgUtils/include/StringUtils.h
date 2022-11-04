/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef DGUS_StringUtils_H
#define DGUS_StringUtils_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _DGUS_StringUtils_t_
{

}DGUS_StringUtils_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
bool_t DGUS_GetStringToChar(char *output,char *input,char find,uint16_t maxSize);
bool_t DGUS_GetStringAfterChar(char *output,char *input,char find,uint16_t maxSize);
bool_t DGUS_GetStringBetweenChars(char *output,char *input,char find,uint16_t maxSize);
bool_t DGUS_GetStringWithNoSpaces(char *output,char *input,uint16_t maxSize);

/* end */
#endif /* DGUS_StringUtils_H */

