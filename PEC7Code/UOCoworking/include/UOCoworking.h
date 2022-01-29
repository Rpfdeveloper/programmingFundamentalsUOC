/*
* File: UOCoworking.h
* Author: Julio Roberto Pajuelo Ferreira
* Date: 09-11-2021
* Description: header file
*/
#include <stdio.h>
#include <stdbool.h>

/*Constants define*/
#define MAX_LENGTH 16

/*types definition*/
typedef enum {STARTUPS,FREELANCERS,RURAL,SPECIALICED,GENERALIST} tCoworkingType;

typedef struct {
    char name[MAX_LENGTH];
    char city[MAX_LENGTH];
	int category;
	tCoworkingType centerType;
	int numSpaces;
	float price;
	float distanceFromCityCenter;
	bool hasMeetingRooms;
	bool hasAuditorium;
}tCoworkingCenter;

/*Funtion and Action declaration*/
void readCenter(tCoworkingCenter *center);

void writeCenter (tCoworkingCenter center);

void copyCenter (tCoworkingCenter centerSrc, tCoworkingCenter *centerDst);

float pointsCenter(tCoworkingCenter center,float price,float distance);

tCoworkingCenter cmpPointsCenter(tCoworkingCenter center1,tCoworkingCenter center2);
