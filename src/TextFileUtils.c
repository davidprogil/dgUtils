/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <TextFileUtils.h>

/* component includes----------------------------------------------------------*/
/* none */

/* local macros ---------------------------------------------------------------*/
/* none */

/* local types ----------------------------------------------------------------*/
/* none */

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
/* none */

/* local prototypes -----------------------------------------------------------*/
/* none */

/* public functions -----------------------------------------------------------*/
void DGUF_Init(DGUF_TextFileUtils_t *this)
{
	printf("DGUF_Init\n");
}

bool_t DGUF_ReadLine(FILE *fh,char *output,uint16_t *outputLenght, uint16_t maxOutputLength)
{
	bool_t isEndOfFile=DG_FALSE;
	uint16_t outIx=0;

	char c=0;
	do
	{
		c=getc(fh);
		if (EOF==c)
		{
			isEndOfFile=DG_TRUE;
		}
		else if ('\n'!=c)
		{
			output[outIx++]=c;
		}
	}while ((c!=EOF)&&(c!='\n'));

	/* wrap-up*/
	output[outIx]=0;
	*outputLenght=outIx+1;

	return isEndOfFile;
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
