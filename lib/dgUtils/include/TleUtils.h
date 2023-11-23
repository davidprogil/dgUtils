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
#define DGUT_TLE_MAX_NO (100)
#define DGUT_TLE_LINE_NB (70)

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
bool_t DGUT_GetTleId4SatCat(uint16_t *tleId,uint32_t satCatId);
bool_t DGUT_GetSatLatLon(DGUT_SatLatLon_t *satLatLon,uint32_t tleId,uint32_t time);
bool_t DGUT_GetSunLatLon(DGUT_SatLatLon_t *satLatLon,uint32_t time);
void DGUT_GetTleEpoch(uint32_t *epoch,uint32_t tleId);
void DGUT_GetTle(uint32_t tleId,char *line1,char *line2);
void DGUT_InjestTle(uint32_t satCatId,char *line1,char *line2);

/* end */
#endif /* DGUT_GeoUtils_H */

