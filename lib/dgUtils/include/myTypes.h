/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/
#ifndef MYTYPES_H
#define MYTYPES_H

/* system includes-------------------------------------------------------------*/
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
/* application includes--------------------------------------------------------*/
/* none */

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
#define M_FALSE (0)
#define M_TRUE (1)

#define ERROR (-1)

#define IS_LITTLE_ENDIAN (1)

#define DGL_DEG2RAD(x) ((x)*3.1415f/180.0f)
#define FLOAT32_MIN (-1.175494350e-38)
#define FLOAT32_MAX (3.40282346e+38)
/* types------------------------------------------------------------------------*/
//#ifndef int8_t
//typedef char int8_t;
//#endif

typedef int8_t bool_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
#ifndef __cplusplus
//#ifndef __GNUC__
#ifndef uint64_t
#ifndef _ARPA_INET_H
typedef unsigned long long uint64_t;
#endif
#endif
#endif
//typedef __uint64_t uint64_t;
//#ifndef __uint64_t
//#define __uint64_t unsigned long long
//#endif
//typedef __uint64_t uint64_t;
//typedef unsigned long long uint64_t;
//#define uint64_t __uint64_t


typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed long int64_t;

typedef float float32_t;
typedef double float64_t;

typedef char shortText_t[40];
typedef char mediumText_t[255];
typedef char longText_t[1024];

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
/* none */


/* end */
#endif /* MYTYPES_H */
