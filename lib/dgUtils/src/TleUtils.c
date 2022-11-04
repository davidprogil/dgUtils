/*******************************************************************************/
/* Copyright David Gil 1998-TODO                                               */
/* 								                                               */
/* davidgil@dgadv.com 			                                               */
/*******************************************************************************/

/* system includes-------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>

/* application includes--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <math.h>

/* component includes----------------------------------------------------------*/
#include "TLE.h"
#include <TleUtils.h>

/* local macros ---------------------------------------------------------------*/
#define DGUT_TLE_MAX_NO (100)
#define DGUT_TLE_LINE_NB (70)
#define DGUT_TLE_ID_NB (8)

#define pio2     1.5707963267949        /* Pi/2 */
#define x3pio2   4.71238898     /* 3*Pi/2 */
#define __f      3.352779E-3
#define xkmper   6.378135E3     /* Earth radius km */
#define secday   8.6400E4       /* Seconds per day */
#define omega_E  1.0027379

/* local types ----------------------------------------------------------------*/
typedef struct VERIN {
	char line1[DGUT_TLE_LINE_NB];
	char line2[DGUT_TLE_LINE_NB];
	double startmin;
	double stepmin;
	double stopmin;
} VERIN;

typedef struct {
	double          x;          /*!< X component */
	double          y;          /*!< Y component */
	double          z;          /*!< Z component */
	double          w;          /*!< Magnitude */
} vector_t;
typedef struct {
	double          lat;        /*!< Latitude [rad] */
	double          lon;        /*!< Longitude [rad] */
	double          alt;        /*!< Altitude [km]? */
	double          theta;
} geodetic_t;

/* public variables -----------------------------------------------------------*/
/* none */

/* local variables ------------------------------------------------------------*/
VERIN verin_g[DGUT_TLE_MAX_NO];
TLE	  tle_g[DGUT_TLE_MAX_NO];
uint32_t tleNo_g;
/* local prototypes -----------------------------------------------------------*/
int readVERINs(shortText_t filename,VERIN *listptr,TLE *tle,uint32_t *tleNo);
double Julian_Date_of_Year(double year);
double Julian_Date_of_Epoch(double epoch);
void Calculate_LatLonAlt(double _time, vector_t * pos, geodetic_t * geodetic);
double Sqr(double arg);
double ThetaG_JD(double jd);
double FMod2p(double x);
double AcTan(double sinx, double cosx);
double Frac(double arg);
double Modulus(double arg1, double arg2);
/* public functions -----------------------------------------------------------*/
bool_t DGUT_ReadAndParseTles(shortText_t filename)
{
	bool_t isError=M_FALSE;
	int32_t readResult;

	readResult=readVERINs(filename,verin_g,tle_g,&tleNo_g);

	if (readResult>0)
	{
		//parse done in readVERINs
	}
	else
	{
		printf("ERROR: DGUT_ReadAndParseTles could not open %s for reading\n",filename);
		isError=M_TRUE;
	}

	return isError;
}

bool_t DGUT_GetTleId(uint32_t *tleId,shortText_t catalogId)
{
	bool_t isError=M_TRUE;
	uint32_t tIx;
	//normalize catalogId
	for (uint8_t cIx=strlen(catalogId);cIx<DGUT_TLE_ID_NB;cIx++)
	{
		catalogId[cIx]=32;
		catalogId[cIx+1]=0;
	}

	//find TLE
	for (tIx=0;tIx<tleNo_g;tIx++)
	{
		printf("DEBUG: checking %s against catalogId %s\n",tle_g[tIx].intlid,catalogId);
		if (!(strcmp(tle_g[tIx].intlid,catalogId)))
		{
			*tleId=tIx;
			isError=M_FALSE;
			break;
		}
	}

	if (tIx==tleNo_g)
	{
		printf("WARNING: DGUT_GetTleId not found for catalogId %s\n",catalogId);
	}
	else
	{
		printf("INFO: DGUT_GetTleId found tleId %d for catalogId %s\n",*tleId,catalogId);
	}

	return isError;
}

bool_t DGUT_GetSunLatLon(DGUT_SatLatLon_t *satLatLon,uint32_t time)
{
	bool_t isError=M_TRUE;
	return isError;
}

bool_t DGUT_GetSatLatLon(DGUT_SatLatLon_t *satLatLon,uint32_t tleId,uint32_t time2)
{
	bool_t isError=M_FALSE;

	//TODO
	double r[3];
	double v[3];
	TLE tle;
	memcpy(&tle,&tle_g[tleId],sizeof(tle));
	long tleEpoch=tle.epoch/1000.0;
	long nowEpoch=time2;
	double mins=(nowEpoch*1.0-tleEpoch*1.0)/60.0;

	getRV(&tle,mins,r,v);
	//printf("tleEpoch %ld nowEpoch %ld  mins: %f r: %f %f %f\n",tleEpoch,nowEpoch,mins,r[0],r[1],r[2]);

	double lati,longi,alti;
	//double rplan;

	geodetic_t geo;
	vector_t pos;

	double          jul_utc;
	pos.x=r[0];    pos.y=r[1];    pos.z=r[2];	pos.w=sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
	jul_utc = Julian_Date_of_Epoch(nowEpoch);
	Calculate_LatLonAlt(jul_utc,&pos,&geo);

	while (geo.lon < -pi)
	{
		//printf("geo.lon1 %f\n",geo.lon);
		geo.lon += twopi;
	}

	while (geo.lon > (pi))
	{
		//printf("geo.lon2 %f\n",geo.lon);
		geo.lon -= twopi;
	}

	lati=geo.lat*180.0/pi;
	longi=geo.lon*180.0/pi;
	alti=geo.alt;

	printf("lati %f longi %f alti %f\n",lati,longi,alti);

	satLatLon->lat=lati;
	satLatLon->lon=longi;
	satLatLon->alt=alti;

	return isError;
}

void DGUT_GetTleEpoch(uint32_t *epoch,uint32_t tleId)
{
	*epoch=tle_g[tleId].epoch/1000;
}

/* local functions ------------------------------------------------------------*/
int readVERINs(shortText_t filename,VERIN *listptr,TLE *tle,uint32_t *tleNo)
{
	char line[256];
	char *str = NULL;
	FILE *in_file = NULL;
	VERIN *verins = NULL;
	int cnt = 0;
	*tleNo=0;

	in_file = fopen(filename,"r");


	if(in_file)
	{
		while(fgets(line,255,in_file) != NULL)
		{
			if(line[0]=='1')cnt++;
		}
		fclose(in_file);

		verins = listptr;

		cnt = 0;
		in_file = fopen(filename,"r");

		while(fgets(line,255,in_file) != NULL)
		{
			if(line[0]=='1')
			{
				strncpy(verins[cnt].line1,line,(DGUT_TLE_LINE_NB-1));
				verins[cnt].line1[(DGUT_TLE_LINE_NB-1)]=0;
				fgets(line,255,in_file);
				strncpy(verins[cnt].line2,line,(DGUT_TLE_LINE_NB-1));
				verins[cnt].line2[(DGUT_TLE_LINE_NB-1)]=0;
				str = &line[DGUT_TLE_LINE_NB];
				sscanf(str,"%lf %lf %lf",&verins[cnt].startmin,&verins[cnt].stopmin,&verins[cnt].stepmin);
				cnt++;
			}
			if (cnt==(DGUT_TLE_MAX_NO-1))
			{
				printf("WARNING: readVERINs stopping max number of TLEs reached %d\n",DGUT_TLE_MAX_NO);
				break;
			}
		}

		printf("INFO: read %d verins\n",cnt);
		fclose(in_file);
		*tleNo=cnt;
		for (uint32_t tIx=0;tIx<cnt;tIx++)
		{
			parseLines(&tle[tIx],verins[tIx].line1,verins[tIx].line2);
		}
	}



	return cnt;
}

double Julian_Date_of_Year(double year)
{
	/* Astronomical Formulae for Calculators, Jean Meeus, */
	/* pages 23-25. Calculate Julian Date of 0.0 Jan year */

	long            A, B, i;
	double          jdoy;

	year = year - 1;
	i = year / 100;
	A = i;
	i = A / 4;
	B = 2 - A + i;
	i = 365.25 * year;
	i += 30.6001 * 14;
	jdoy = i + 1720994.5 + B;

	return (jdoy);
}
double Julian_Date_of_Epoch(double epoch)
{
	return (Julian_Date_of_Year(1970) + epoch*1.0/(24*60*60+0.0*0.0042 ));
}

void Calculate_LatLonAlt(double _time, vector_t * pos, geodetic_t * geodetic)
{
	/* Reference:  The 1992 Astronomical Almanac, page K12. */

	double          r, e2, phi, c;

	geodetic->theta = AcTan(pos->y, pos->x);    /* rad */
	geodetic->lon = FMod2p(geodetic->theta - ThetaG_JD(_time)); /* rad */
	r = sqrt(Sqr(pos->x) + Sqr(pos->y));
	e2 = __f * (2 - __f);
	geodetic->lat = AcTan(pos->z, r);   /* rad */

	do
	{
		phi = geodetic->lat;
		c = 1 / sqrt(1 - e2 * Sqr(sin(phi)));
		geodetic->lat = AcTan(pos->z + xkmper * c * e2 * sin(phi), r);
	}
	while (fabs(geodetic->lat - phi) >= 1E-10);

	geodetic->alt = r / cos(geodetic->lat) - xkmper * c;        /* km */

	if (geodetic->lat > pio2)
		geodetic->lat -= twopi;
}

double Sqr(double arg)
{
	return (arg * arg);
}
double ThetaG_JD(double jd)
{
	/* Reference:  The 1992 Astronomical Almanac, page B6. */

	double          UT, TU, GMST;

	UT = Frac(jd + 0.5);
	jd = jd - UT;
	TU = (jd - 2451545.0) / 36525;
	GMST = 24110.54841 + TU * (8640184.812866 + TU * (0.093104 - TU * 6.2E-6));
	GMST = Modulus(GMST + secday * omega_E * UT, secday);

	return (twopi * GMST / secday);
}
double FMod2p(double x)
{
	int             i;
	double          ret_val;

	ret_val = x;
	i = ret_val / twopi;
	ret_val -= i * twopi;
	if (ret_val < 0)
		ret_val += twopi;

	return (ret_val);
}

double AcTan(double sinx, double cosx)
{
	if (cosx == 0)
	{
		if (sinx > 0)
			return (pio2);
		else
			return (x3pio2);
	}
	else
	{
		if (cosx > 0)
		{
			if (sinx > 0)
				return (atan(sinx / cosx));
			else
				return (twopi + atan(sinx / cosx));
		}
		else
			return (pi + atan(sinx / cosx));
	}

}

double Frac(double arg)
{
	return (arg - floor(arg));
}
double Modulus(double arg1, double arg2)
{
	int             i;
	double          ret_val;

	ret_val = arg1;
	i = ret_val / arg2;
	ret_val -= i * arg2;
	if (ret_val < 0)
		ret_val += arg2;

	return (ret_val);
}
/* end */
