/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef DGUH_MathUtils_H
#define DGUH_MathUtils_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define DGUH_PI (3.14159f)
#define DGUH_RAD2DEG(x) ((x)/DGUH_PI*180.0f)
#define DGUH_DEG2RAD(x) ((x)*DGUH_PI/180.0f)

/* types------------------------------------------------------------------------*/
typedef struct _DGUH_MathUtils_t_
{

}DGUH_MathUtils_t;

typedef struct _DGUH_Float32MovingAverage_t_
{
	float32_t sum;
	float32_t average;
	uint16_t  samplesNb;
	uint16_t  samplesNbMax;
}DGUH_Float32MovingAverage_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void DGUH_Init(DGUH_MathUtils_t *this);
void DGUH_Execute(DGUH_MathUtils_t *this);

//DGUH_Float32MovingAverage_t
void DGUH_Init_Float32MovingAverage(DGUH_Float32MovingAverage_t *this,uint16_t samplesNbMax);
float32_t DGUH_Recalculate_Float32MovingAverage(DGUH_Float32MovingAverage_t *this,float32_t newSample);
float32_t DGUH_Error(float32_t one,float32_t two);
float32_t DGUH_sampleNormal(float32_t center,float32_t cov);
bool_t DGUH_uint16_isOdd(uint16_t input);
float32_t DGUH_Float32_Min(float32_t one,float32_t two);
float32_t DGUH_Float32_Max(float32_t one,float32_t two);
int16_t DGUH_Int16_Min(int16_t one,int16_t two);
int16_t DGUH_Int_Max(int16_t one,int16_t two);

/* end */
#endif /* DGUH_MathUtils_H */

