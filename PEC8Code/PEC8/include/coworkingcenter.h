/*
* File: coworkingcenter.h
* Author: UOC and Julio Roberto Pajuelo Ferreira
* Course: 20211
* Description: PAC8-PEC8-CAA8
*/
#include <stdio.h>
#include <stdbool.h>
#define ONE 1
#define ZERO 0

#define MAX_CENTERS 100
#define MAX_NAME 15+1
#define MAX_CITY 15+1

#define MAX_LINE 514

#define FACILITIES_POINTS 5.0  /* Point for facilities */
#define OPTIMAL_WORKSPACES 3   /* Optimal amount of workspaces */

typedef enum {STARTUPS=1, FREELANCERS, RURAL, SPECIALIZED, GENERALIST} tCoworkingType;

typedef struct {
    char name[MAX_NAME];
	char city[MAX_CITY];
    int category;
    tCoworkingType centerType;
	int numSpaces;
    float price; 
    float distanceFromCityCenter;
    bool hasMeetingRooms;
    bool hasAuditorium;
	float percentOccupation;
} tCoworkingCenter;

typedef struct { 
	tCoworkingCenter centers[MAX_CENTERS];
	int numCenters;
}tCoworkingCentersTable;

//headers
void writeCenter(tCoworkingCenter center);
void copyCenter (tCoworkingCenter centerSrc, tCoworkingCenter *centerDst);
float pointsCenter (tCoworkingCenter center, float price, float distance);

void getCenterObject(const char *str, tCoworkingCenter *center);
void centersTableAddElement(tCoworkingCentersTable *centersTable, tCoworkingCenter center);
void centersTableLoadDataFromFile(tCoworkingCentersTable *centersTable, const char* filename, bool *isRead);

/* initialization table action*/
void centersTableInitialize(tCoworkingCentersTable *tCenter);
/*Select table action*/
void centersTableSelect(tCoworkingCentersTable tInitialCenter,char city[MAX_CITY],float optDist, float optPrice,float ndPoints,tCoworkingCentersTable *newTCenter);
/*Average Occupation Funtion*/
float centersAverageOccupation(tCoworkingCentersTable tCenterIn, char city[MAX_CITY]);