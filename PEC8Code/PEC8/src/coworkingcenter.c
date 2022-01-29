/*
* File: coworkingcenter.c
* Author: UOC and Julio Roberto Pajuelo Ferreira
* Course: 20211
* Description: PAC8-PEC8-CAA8
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coworkingcenter.h"

void writeCenter(tCoworkingCenter center)
{
    printf("CENTER'S DATA: \n");
	printf("NAME: %s\n", center.name);
	printf("CITY: %s\n", center.city);
	printf("CATEGORY (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3): %u\n", center.category);
	printf("CENTER TYPE (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST): %u\n", center.centerType);
	printf("NUM. SPACES: %d\n", center.numSpaces);
	printf("PRICE: %.2f\n", center.price);
	printf("DISTANCE TO CITY CENTER IN KM: %.2f\n", center.distanceFromCityCenter);	
	printf("HAS MEETING ROOMS (0-FALSE, 1-TRUE): %d\n", center.hasMeetingRooms);
	printf("HAS AUDITORIUM (0-FALSE, 1-TRUE): %d\n", center.hasAuditorium);
	printf("PERCENT OCCUPATION: %.2f\n", center.percentOccupation);
}

void copyCenter (tCoworkingCenter centerSrc, tCoworkingCenter *centerDst)
{
	strcpy(centerDst->name, centerSrc.name);
	strcpy(centerDst->city, centerSrc.city);
	centerDst->category = centerSrc.category;
	centerDst->centerType = centerSrc.centerType;
	centerDst->numSpaces = centerSrc.numSpaces;
	centerDst->price = centerSrc.price;
	centerDst->distanceFromCityCenter = centerSrc.distanceFromCityCenter;
	centerDst->hasMeetingRooms = centerSrc.hasMeetingRooms;
	centerDst->percentOccupation = centerSrc.percentOccupation;
}

float pointsCenter (tCoworkingCenter center, float price, float distance)
{
	float points = 0.0;		
	points = (price - center.price) / price;	
	points = points + ((distance - center.distanceFromCityCenter) / distance);
	
	if (center.hasMeetingRooms || center.hasAuditorium) {
		points = points + FACILITIES_POINTS;		
	}
	if (center.numSpaces >= OPTIMAL_WORKSPACES) {
		points = points + FACILITIES_POINTS;
	}
	
	return (points);
} 

void getCenterObject(const char *str, tCoworkingCenter *center)
{
	int aux_type, aux_meeteng_rooms, aux_auditorium;
	
	/* read center data */
	sscanf(str, "%s %s %d %u %d %f %f %u %u %f",
	center->name,
	center->city,
	&center->category,
	&aux_type,
	&center->numSpaces,
	&center->price,
	&center->distanceFromCityCenter,
	&aux_meeteng_rooms,
	&aux_auditorium,
	&center->percentOccupation);

	center->centerType=(tCoworkingType)aux_type;	
	center->hasMeetingRooms=(bool)aux_meeteng_rooms;
	center->hasAuditorium=(bool)aux_auditorium;	
}

void centersTableAddElement(tCoworkingCentersTable *centersTable, tCoworkingCenter center)
{
	/* Check if there enough space for the new hotel */
	if(centersTable->numCenters >= MAX_CENTERS) {
		printf("ERROR ADDING A CENTER INTO TABLE\n");
	}
	else {
		/* Add the new center to the end of the table */
		copyCenter(center, &centersTable->centers[centersTable->numCenters]);
		centersTable->numCenters++;
	}	
}

void centersTableLoadDataFromFile(tCoworkingCentersTable *centersTable, const char* filename, bool *isRead)
{
	FILE *fin=0;
	char line[MAX_LINE];
	tCoworkingCenter newCenter;

	/* Open the input file */
	if((fin=fopen(filename,"r"))!=NULL) {
		/* Read all the hotels */
		while(!feof(fin) && centersTable->numCenters < MAX_CENTERS) {
			/* Remove any content from the line */
			line[0]='\0';
			/* Read one line (maximum 511 chars) and store it in "line" variable */
			fgets(line,MAX_LINE-1,fin);
			/* Ensure that the string is ended by 0*/
			line[MAX_LINE-1]='\0';
			if(strlen(line)>0) {
				/* Obtain the object */
				getCenterObject(line, &newCenter);
				/* Add the new hotel to the output table */
				centersTableAddElement(centersTable, newCenter);
			}
		}
		/* Close the file */
		fclose(fin);
		*isRead = true;
	}
	else {
		printf("FILE NOT FOUND\n");
		*isRead = false;
	}
}

/* Exercises */

/* Exercise 2.1 */
void centersTableInitialize(tCoworkingCentersTable *tCenter){
	
	tCenter->numCenters = ZERO;
}
/* Exercise 2.2 */
void centersTableSelect(tCoworkingCentersTable tInitialCenter,char city[MAX_CITY],float optDist, float optPrice,float ndPoints,tCoworkingCentersTable *newTCenter){
	
	int i;
	
	centersTableInitialize(newTCenter);
	
	for (i = ZERO; i < tInitialCenter.numCenters;i++){
		if(strcmp(tInitialCenter.centers[i].city,city) == ZERO && pointsCenter(tInitialCenter.centers[i],optPrice,optDist) >= ndPoints){
			
			copyCenter(tInitialCenter.centers[i],&newTCenter->centers[newTCenter->numCenters]);
			newTCenter->numCenters ++;
				
			
		}
	}
}
/* Exercise 2.3 */
float centersAverageOccupation(tCoworkingCentersTable tCenterIn,char city[MAX_CITY]){
	
	int i;
	int totalSpaces = ZERO;
	int totalSpacesOccuped = ZERO;
	float result = 0.0;
	for (i = ZERO;i < tCenterIn.numCenters; i++){
		if (strcmp(city,tCenterIn.centers[i].city) == ZERO){
			totalSpacesOccuped += (int)(tCenterIn.centers[i].numSpaces * (tCenterIn.centers[i].percentOccupation/100.0));
			totalSpaces += tCenterIn.centers[i].numSpaces;
		}
	}
	if(totalSpaces > ZERO){
		result = 100.0 *(float)totalSpacesOccuped/(float)totalSpaces;
	}
		return result;
	

}