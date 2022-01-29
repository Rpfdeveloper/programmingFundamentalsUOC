/*
* File: main.c
* Author: Julio Roberto Pajuelo Ferreira
* Date: 02-11-2021
* Description: Modularidad 
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Constant declaration */
#define MAX_LENGTH 16
#define ZERO 0
#define ONE 1
#define MINUS_ONE -1


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
/*Exercise 2.1.1*/
void readCenter(tCoworkingCenter *center);

/*Exercise 2.2.1*/
void writeCenter (tCoworkingCenter center);

/*Exercise 2.3.1*/
bool isAcceptableCenter(tCoworkingCenter center,float price,float distance);

/*Exercise 2.4.1*/
int bestCenter(tCoworkingCenter center1,tCoworkingCenter center2);

int main(int argc, char **argv)
{
	tCoworkingCenter center1;
	tCoworkingCenter center2;
	int theBestCenter;
	float price;
	float distance;
	
	/*Exercise 2.5*/
	/*Data input Center1*/
	printf("ENTER DATA FOR CENTER 1\n");
	readCenter(&center1);
	
	/*Data input Center2*/
	printf("ENTER DATA FOR CENTER 2\n");
	readCenter(&center2);
	
	/*Data input acceptable price*/
	printf("ACCEPTABLE PRICE [EUR]? >>\n");
	scanf("%f",&price);
	
	/*Data input acceptable price*/
	printf("ACCEPTABLE DISTANCE FROM CITY CENTER [KM]? >>\n");
	scanf("%f",&distance);
	
	printf("RESULTS\n");
	
	if(isAcceptableCenter(center1,price,distance) && isAcceptableCenter(center2,price,distance) && strcmp(center1.city, center2.city) == ZERO){
		
		theBestCenter = bestCenter(center1,center2);
		
		if(theBestCenter == ZERO || theBestCenter == ONE){
			
			printf("CENTER 1 SUITS YOU BETTER, AND THE DATA ARE: \n");
			
			writeCenter(center1);
			
			printf("THE SECOND BEST CENTER IS CENTER 2 AND THE DATA ARE: \n");
			
			writeCenter(center2);
		
		}else{
			
			printf("CENTER 2 SUITS YOU BETTER, AND THE DATA ARE: \n");
			
			writeCenter(center2);
		
			printf("THE SECOND BEST CENTER IS CENTER 1 AND THE DATA ARE: \n");
			
			writeCenter(center1);
			
		}
	}else{
		
		printf("CENTERS CAN'T BE COMPARED\n");
		 
	}
	
	
	return ZERO;
}

/**/
/*Exercise 2.1.2*/
void readCenter(tCoworkingCenter *center) {
	int intToBoolAuditorium;
	int intToBoolHasMeetingRooms;
	printf("NAME? (A STRING) >>\n");
	scanf("%s", center -> name);
	printf("CITY? (A STRING) >>\n");
	scanf("%s", center -> city);
	printf("CATEGORY? (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3) >>\n");
	scanf("%d", &center -> category);
	printf("CENTER TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
	scanf("%u", &center -> centerType);
	printf("NUM. SPACES? (AN INTEGER) >>\n");
	scanf("%d", &center -> numSpaces);
	printf("PRICE EUR? (A REAL) >>\n");
	scanf("%f", &center -> price);
	printf("DISTANCE TO CITY CENTER [KM]? (A REAL) >>\n");
	scanf("%f", &center -> distanceFromCityCenter);
	printf("HAS MEETING ROOMS? (0-FALSE, 1-TRUE) >>\n");
	scanf("%d", &intToBoolHasMeetingRooms);
	center -> hasMeetingRooms = (bool)intToBoolHasMeetingRooms;
	printf("HAS AUDITORIUM? (0-FALSE, 1-TRUE) >>\n");
	scanf("%d", &intToBoolAuditorium);
	center -> hasAuditorium = (bool)intToBoolAuditorium;
	
    
}

void writeCenter (tCoworkingCenter center){
	printf("CENTER'S DATA:\n");
	printf("NAME: %s\n",center.name);
	printf("CITY: %s\n",center.city);
	printf("CATEGORY (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3): %d\n",center.category);
	printf("CENTER TYPE (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST): %u\n",center.centerType);
	printf("NUM. SPACES: %d\n",center.numSpaces);
	printf("PRICE: %.2f\n",center.price);
	printf("DISTANCE TO CITY CENTER [KM]: %.2f\n",center.distanceFromCityCenter);
	printf("HAS MEETING ROOMS (0-FALSE, 1-TRUE): %d\n",center.hasMeetingRooms);
	printf("HAS AUDITORIUM (0-FALSE, 1-TRUE): %d\n",center.hasAuditorium);
	
}

bool isAcceptableCenter(tCoworkingCenter center,float price,float distance){
	
	bool isAcceptable;
	
	isAcceptable = (((center.hasMeetingRooms || center.hasAuditorium) && center.price <= price && center.distanceFromCityCenter <= distance));
	
	return isAcceptable;
}


int bestCenter(tCoworkingCenter center1,tCoworkingCenter center2){
	
	int best_Center;
	
	if(center1.category > center2.category){
		
		best_Center = ONE;
	
	}else{
		
		if(center2.category > center1.category){
			
			best_Center = MINUS_ONE;
			
		}else{
			
			if(center1.distanceFromCityCenter < center2.distanceFromCityCenter){
				
				best_Center = ONE;
				
			}else{
				if(center2.distanceFromCityCenter < center1.distanceFromCityCenter){
					
					best_Center = MINUS_ONE;
					
				}else{
					
					if(center1.hasMeetingRooms && center2.hasMeetingRooms == false){
						
						best_Center = ONE;
					
					}else{
						if(center2.hasMeetingRooms && center1.hasMeetingRooms == false){
							
							best_Center = MINUS_ONE;
						
						}else{
							
							best_Center = ZERO;
							
						}
												
					}
				}
			}
		}
	}
	
	return best_Center;
  
}
