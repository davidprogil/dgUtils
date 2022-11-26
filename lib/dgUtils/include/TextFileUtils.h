/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef DGUF_TextFileUtils_H
#define DGUF_TextFileUtils_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _DGUF_TextFileUtils_t_
{

}DGUF_TextFileUtils_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void DGUF_Init(DGUF_TextFileUtils_t *this);
bool_t DGUF_ReadLine(FILE *fh,char *output,uint16_t *outputLenght, uint16_t maxOutputLength);
bool_t DGUF_ReadToChar(FILE *fh,char *output,uint16_t *outputLenght, uint16_t maxOutputLength,char toChar);


/* end */
#endif /* DGUF_TextFileUtils_H */

