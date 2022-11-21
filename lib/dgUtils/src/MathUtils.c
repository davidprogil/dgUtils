/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
	this->sumStdDev=0.0f;
	this->samplesNbMax=samplesNbMax;
	this->average=0.0f;
	this->stdDev=0.0f;
}
float32_t DGUH_Recalculate_Float32MovingAverage(DGUH_Float32MovingAverage_t *this,float32_t newSample)
{
	this->sum+=newSample;
	this->samplesNb++;
	this->average=this->sum/(1.0f*this->samplesNb);
	this->sumStdDev+=sqrt((newSample-this->average)*(newSample-this->average));
	this->stdDev=this->sumStdDev/(1.0f*(this->samplesNb));
	if (this->samplesNb>this->samplesNbMax)
	{
		this->samplesNb=this->samplesNbMax;
		this->sum-=this->average;
	}
	return this->average;
}

float32_t DGUH_Error(float32_t one,float32_t two)
{
	float32_t dif=one-two;
	return sqrt(dif*dif);
}
float64_t DGUH_Error64(float64_t one,float64_t two)
{
	float64_t dif=one-two;
		return sqrt(dif*dif);
}
float32_t DGUH_sampleNormal(float32_t center,float32_t cov)
{
	float32_t drand1=(rand()+1.0)/(RAND_MAX+1.0);
	float32_t drand2=(rand()+1.0)/(RAND_MAX+1.0);
	float32_t normal01=sqrt(-2*log(drand1)) * cos(2*M_PI*drand2);
	return center+sqrt(cov)*normal01;
}
bool_t DGUH_uint16_isOdd(uint16_t input)
{
	bool_t returnValue=M_TRUE;
	if (input%2==0) returnValue=M_FALSE;
	return returnValue;
}

float32_t DGUH_Float32_Min(float32_t one,float32_t two)
{
	if (one<two) return one;
	else return two;
}
float32_t DGUH_Float32_Max(float32_t one,float32_t two)
{
	if (one>two) return one;
		else return two;
}
int16_t DGUH_Int16_Min(int16_t one,int16_t two)
{
	if (one<two) return one;
		else return two;
}
int16_t DGUH_Int_Max(int16_t one,int16_t two)
{
	if (one>two) return one;
			else return two;
}
/* local functions ------------------------------------------------------------*/
/* none */

/* end */
