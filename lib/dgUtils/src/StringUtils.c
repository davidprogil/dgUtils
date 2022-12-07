/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	bool_t isError = M_TRUE;
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
			isError = M_FALSE;
			break;
		}

		srcIx++;
	}while ((c!=0)&&(srcIx<maxSize));

	if (srcIx==maxSize)
	{
		//printf("DGUS_GetStringToChar max size reached\n");//DEBUG
		isError = M_TRUE;
	}

	return isError;
}

bool_t DGUS_GetStringAfterChar(char *output,char *input,char find,uint16_t maxSize)
{
	bool_t isError = M_TRUE;
	uint16_t srcIx=0;
	uint16_t trgIx=0;
	char c=0;

	do
	{
		c=input[srcIx];
		//printf("%c%c",find,c);//DEBUG
		if ((c==find) && (M_TRUE == isError))
		{
			//printf("F");//DEBUG
			isError = M_FALSE;
		}
		else if (M_FALSE == isError)
		{
			output[trgIx++]=c;
		}

		srcIx++;
	}while ((c!=0)&&(srcIx<maxSize));

	return isError;
}

bool_t DGUS_GetStringBetweenChars(char *output,char *input,char find,uint16_t maxSize)
{
	bool_t isError = M_FALSE;

	isError=DGUS_GetStringAfterChar(output,input,find,maxSize);

	if (M_FALSE==isError)
	{
		isError=DGUS_GetStringToChar(output,output,find,maxSize);
	}

	return isError;

}

bool_t DGUS_GetStringWithNoSpaces(char *output,char *input,uint16_t maxSize)
{
	bool_t isError = M_FALSE;
	uint32_t oIx=0;
	char c;
	for (uint32_t bIx=0;bIx<strlen(input);bIx++)
	{
		c=input[bIx];
		if (c!=' ')
		{
			output[oIx++]=c;
			output[oIx]=0;
		}

		if (oIx>=maxSize-1)
		{
			isError = M_TRUE;
			break;
		}
	}
	return isError;
}

void DGUS_ReplaceCharacterByString(char *output,char *input,char find,char *replace)
{
	uint32_t replaceNb=strlen(replace);
	uint32_t inputNb=strlen(input);
	uint32_t iIx;
	uint32_t oIx;

	oIx=0;
	for (iIx=0;iIx<inputNb;iIx++)
	{
		if (input[iIx]==find)
		{
			strcpy(&output[oIx],replace);
			oIx+=replaceNb;
		}
		else
		{
			output[oIx++]=input[iIx];
		}
		output[oIx]=0;
	}
}


/* local functions ------------------------------------------------------------*/
/* none */

/* end */
