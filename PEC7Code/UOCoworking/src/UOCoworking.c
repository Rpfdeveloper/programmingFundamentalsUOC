/*
* File: UOCoworking.c
* Author: Julio Roberto Pajuelo Ferreira
* Date: 09-11-2021
* Description: Feature and action deployment file
*/

#include <stdio.h>
#include <string.h>
#include "UOCoworking.h"

#define PERCENT 100.0
#define TEN_POINTS 10.0
#define POINTS_FACILITIES 5.0
#define OPTIMAL_WORKSPACES 3
#define ZERO 0.0
#define TREE 3


/*center data reading function*/
void readCenter(tCoworkingCenter *center) {
	int intToBoolAuditorium;
	int intToBoolHasMeetingRooms;
	printf("NAME (A STRING) >>\n");
	scanf("%s", center -> name);
	printf("CITY? (A STRING) >>\n");
	scanf("%s", center -> city);
	printf("CATEGORY? (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3) >>\n");
	scanf("%d", &center -> category);
	printf("CENTER TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
	scanf("%u", &center -> centerType);
	printf("NUM. SPACES? (AN INTEGER) >>\n");
	scanf("%d", &center -> numSpaces);
	printf("PRICE (A REAL) >>\n");
	scanf("%f", &center -> price);
	printf("DISTANCE TO CITY CENTER IN KM (A REAL) >>\n");
	scanf("%f", &center -> distanceFromCityCenter);
	printf("HAS MEETING ROOMS (0-FALSE, 1-TRUE)? >>\n");
	scanf("%d", &intToBoolHasMeetingRooms);
	center -> hasMeetingRooms = (bool)intToBoolHasMeetingRooms;
	printf("HAS AUDITORIUM (0-FALSE, 1-TRUE)? >>\n");
	scanf("%d", &intToBoolAuditorium);
	center -> hasAuditorium = (bool)intToBoolAuditorium;
}

/*data writing function of the centers*/
void writeCenter (tCoworkingCenter center){
	printf("CENTER'S DATA:\n");
	printf("NAME: %s\n",center.name);
	printf("CITY: %s\n",center.city);
	printf("CATEGORY (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3): %d\n",center.category);
	printf("CENTER TYPE (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST): %u\n",center.centerType);
	printf("NUM. SPACES: %d\n",center.numSpaces);
	printf("PRICE: %.2f\n",center.price);
	printf("DISTANCE TO CITY CENTER IN KM: %.2f\n",center.distanceFromCityCenter);
	printf("HAS MEETING ROOMS (0-FALSE, 1-TRUE): %d\n",center.hasMeetingRooms);
	printf("HAS AUDITORIUM (0-FALSE, 1-TRUE): %d\n",center.hasAuditorium);
	
}

/*stuctured data copy function*/
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
	centerDst->hasAuditorium = centerSrc.hasAuditorium;
}

/*point calculation function*/
float pointsCenter(tCoworkingCenter center,float price,float distance){
	
	float points;
	points = ZERO;
	if((center.hasMeetingRooms || center.hasAuditorium) && center.numSpaces >= OPTIMAL_WORKSPACES){
		
		points = TEN_POINTS;
	
	}else{
		if(center.hasMeetingRooms || center.hasAuditorium){
			
			points = POINTS_FACILITIES;
		
		}else{
			if(center.numSpaces >= TREE){
				
				points = POINTS_FACILITIES;
			
			}
		}
	}
	points = points + (PERCENT * (price - center.price) / price);
	points = points + (PERCENT * (distance - center.distanceFromCityCenter) / distance);
	return points;
}

/*function to compare the centers by their points*/
tCoworkingCenter cmpPointsCenter(tCoworkingCenter center1,tCoworkingCenter center2){

	float price = ZERO;
	float distance = ZERO;
	tCoworkingCenter bestCenter;
	
	/*Data input optimal price*/
	printf("OPTIMAL DISTANCE [KM]? (A REAL) >>\n");
	scanf("%f",&distance);
	/*Data input optimal price*/
	printf("OPTIMAL PRICE [EUR]? (A REAL)>>\n");
	scanf("%f",&price);
	
	

	if(pointsCenter(center1,price,distance)>= pointsCenter(center2,price,distance)){
		
		copyCenter(center1,&bestCenter);
		
	}else{
		
		copyCenter(center2,&bestCenter);
		
	}
	
	
	return bestCenter;
}
