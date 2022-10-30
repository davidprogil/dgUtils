/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

#ifndef DGUT_GeoUtils_H
#define DGUT_GeoUtils_H

/* system includes-------------------------------------------------------------*/
/* none */

/* application includes--------------------------------------------------------*/
#include <myTypes.h>

/* component includes----------------------------------------------------------*/
/* none */

/* macros-----------------------------------------------------------------------*/
/* none */

/* types------------------------------------------------------------------------*/
typedef struct _DGUT_SatLatLon_t_
{
	float64_t	lat;	float64_t	lon;	float64_t	alt;
}DGUT_SatLatLon_t;

/* public variables-------------------------------------------------------------*/
/* none */

/* public functions--------------------------------------------------------------*/
bool_t DGUT_ReadAndParseTles(shortText_t filename);
bool_t DGUT_GetTleId(uint32_t *tleId,shortText_t catalogId);
bool_t DGUT_GetSatLatLon(DGUT_SatLatLon_t *satLatLon,uint32_t tleId,uint32_t time);
//get sun lat lon - time TODO


/* end */
#endif /* DGUT_GeoUtils_H */

