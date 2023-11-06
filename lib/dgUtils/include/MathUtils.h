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

#define DGUH_FLOAT64_PI (3.1415926535897932384626433832795028841971693993751058209749445923078164062)
#define DGUH_FLOAT64_RAD2DEG(x) ((x)/DGUH_FLOAT64_PI*180.0)
#define DGUH_FLOAT64_DEG2RAD(x) ((x)*DGUH_FLOAT64_PI/180.0)

/* types------------------------------------------------------------------------*/
typedef struct _DGUH_MathUtils_t_
{

}DGUH_MathUtils_t;

typedef struct _DGUH_Float32MovingAverage_t_
{
	float32_t sum;
	float32_t average;
	float32_t stdDev;
	float32_t sumStdDev;
	uint16_t  samplesNb;
	uint16_t  samplesNbMax;
}DGUH_Float32MovingAverage_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
void DGUH_Init(DGUH_MathUtils_t *self);
void DGUH_Execute(DGUH_MathUtils_t *self);

//DGUH_Float32MovingAverage_t
void DGUH_Init_Float32MovingAverage(DGUH_Float32MovingAverage_t *self,uint16_t samplesNbMax);
float32_t DGUH_Recalculate_Float32MovingAverage(DGUH_Float32MovingAverage_t *self,float32_t newSample);
float32_t DGUH_Error(float32_t one,float32_t two);
float64_t DGUH_Error64(float64_t one,float64_t two);
float32_t DGUH_sampleNormal(float32_t center,float32_t cov);
bool_t DGUH_uint16_isOdd(uint16_t input);
float32_t DGUH_Float32_Min(float32_t one,float32_t two);
float32_t DGUH_Float32_Max(float32_t one,float32_t two);
float32_t DGUH_Float32_Interpolate(float32_t max,float32_t min,float32_t factor);
float64_t DGUH_Float64_Interpolate(float64_t max,float64_t min,float64_t factor);
int16_t DGUH_Int16_Min(int16_t one,int16_t two);
int16_t DGUH_Int_Max(int16_t one,int16_t two);


/* end */
#endif /* DGUH_MathUtils_H */

