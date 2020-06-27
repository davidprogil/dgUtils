/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <StringUtils.h>

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
bool_t DGUS_GetStringToChar(char *output,char *input,char find,uint16_t maxSize)
{
	bool_t isError = DG_TRUE;
	uint16_t srcIx=0;
	char c=0;

	do
	{
		c=input[srcIx];
		//printf("%c%c",find,c);//DEBUG
		if (c!=find)
		{
			output[srcIx]=c;
		}
		else
		{
			output[srcIx]=0;
			isError = DG_FALSE;
			break;
		}

		srcIx++;
	}while ((c!=0)&&(srcIx<maxSize));

	if (srcIx==maxSize)
	{
		//printf("DGUS_GetStringToChar max size reached\n");//DEBUG
		isError = DG_TRUE;
	}

	return isError;
}

bool_t DGUS_GetStringAfterChar(char *output,char *input,char find,uint16_t maxSize)
{
	bool_t isError = DG_TRUE;
	uint16_t srcIx=0;
	uint16_t trgIx=0;
	char c=0;

	do
	{
		c=input[srcIx];
		//printf("%c%c",find,c);//DEBUG
		if ((c==find) && (DG_TRUE == isError))
		{
			//printf("F");//DEBUG
			isError = DG_FALSE;
		}
		else if (DG_FALSE == isError)
		{
			output[trgIx++]=c;
		}

		srcIx++;
	}while ((c!=0)&&(srcIx<maxSize));

	return isError;
}

bool_t DGUS_GetStringBetweenChars(char *output,char *input,char find,uint16_t maxSize)
{
	bool_t isError = DG_FALSE;

	isError=DGUS_GetStringAfterChar(output,input,find,maxSize);

	if (DG_FALSE==isError)
	{
		isError=DGUS_GetStringToChar(output,output,find,maxSize);
	}

	return isError;

}


/* local functions ------------------------------------------------------------*/
/* none */

/* end */
