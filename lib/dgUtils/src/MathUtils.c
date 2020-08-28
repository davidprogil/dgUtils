/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <MathUtils.h>

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
void DGUH_Init(DGUH_MathUtils_t *this)
{
	printf("DGUH_Init\n");
}

void DGUH_Execute(DGUH_MathUtils_t *this)
{
	printf("DGUH_Execute\n");
}

void DGUH_Init_Float32MovingAverage(DGUH_Float32MovingAverage_t *this,uint16_t samplesNbMax)
{
	this->samplesNb=0;
	this->sum=0.0f;
	this->samplesNbMax=samplesNbMax;
	this->average=0.0f;
}
float32_t DGUH_Recalculate_Float32MovingAverage(DGUH_Float32MovingAverage_t *this,float32_t newSample)
{
	this->sum+=newSample;
	this->samplesNb++;
	this->average=this->sum/(1.0f*this->samplesNb);
	if (this->samplesNb>this->samplesNbMax)
	{
		this->samplesNb=this->samplesNbMax;
		this->sum-=this->average;
	}
	return this->average;
}

/* local functions ------------------------------------------------------------*/
/* none */

/* end */
