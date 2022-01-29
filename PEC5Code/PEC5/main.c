/*
* File: main.c
* Author: Julio Roberto Pajuelo Ferreira
* Date: 26-10-2021
* Description: Tipos de datos estructurados 
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* Constant declaration */
#define MAX_LENGTH 16
#define ZERO 0

/*typedef definition*/
typedef enum {STARTUPS,FREELANCERS,RURAL,SPECIALICED,GENERALIST} tCoworkingType;

/* Types definition */
typedef struct {
    char name[MAX_LENGTH];
    char city[MAX_LENGTH];
	int category;
	tCoworkingType centerType;
	float price;
	float distanceFromCityCenter;	
}tCoworkingCenter;

/*funtion main*/
int main(int argc, char **argv)
{
	/*var declaration*/
	char city[MAX_LENGTH];
	float maxPrice;
	tCoworkingCenter bestCenter;
	bool isCenter1;
	bool isCenter2;
	bool isCenter3;
	/*Exercise 2.1*/
	tCoworkingCenter center1;
	tCoworkingCenter center2;
	tCoworkingCenter center3;
	
	
	/*Exercise 2.2*/
	/*Data input center 1*/
	printf("ENTER DATA FOR CENTER 1\n");
	printf("NAME? (A STRING) >>\n");
	scanf("%s", center1.name);
	printf("CITY? (A STRING) >>\n");
	scanf("%s", center1.city);
	printf("CATEGORY? (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3) >>\n");
	scanf("%d", &center1.category);
	printf("CENTER TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
	scanf("%u", &center1.centerType);
	printf("PRICE EUR?(A REAL) >>\n");
	scanf("%f", &center1.price);
	printf("DISTANCE TO CITY CENTER [KM]? (A REAL) >>\n");
	scanf("%f", &center1.distanceFromCityCenter);
	
	/*Data input center 2*/
	printf("ENTER DATA FOR CENTER 2\n");
	printf("NAME? (A STRING) >>\n");
	scanf("%s", center2.name);
	printf("CITY? (A STRING) >>\n");
	scanf("%s", center2.city);
	printf("CATEGORY? (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3) >>\n");
	scanf("%d", &center2.category);
	printf("CENTER TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
	scanf("%u", &center2.centerType);
	printf("PRICE EUR?(A REAL) >>\n");
	scanf("%f", &center2.price);
	printf("DISTANCE TO CITY CENTER [KM]? (A REAL) >>\n");
	scanf("%f", &center2.distanceFromCityCenter);
	
	/*Data input center 3*/
	printf("ENTER DATA FOR CENTER 3\n");
	printf("NAME? (A STRING) >>\n");
	scanf("%s", center3.name);
	printf("CITY? (A STRING) >>\n");
	scanf("%s", center3.city);
	printf("CATEGORY? (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3) >>\n");
	scanf("%d", &center3.category);
	printf("CENTER TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
	scanf("%u", &center3.centerType);
	printf("PRICE EUR?(A REAL) >>\n");
	scanf("%f", &center3.price);
	printf("DISTANCE TO CITY CENTER [KM]? (A REAL) >>\n");
	scanf("%f", &center3.distanceFromCityCenter);
	
	/*DATA INPUT*/
	printf("MAX PRICE EUR? (A REAL) >>\n");
	scanf("%f", &maxPrice);
	printf("CITY? (A STRING) >>\n");
	scanf("%s", city);
	
	/*Exercise 2.3*/
	/*Data processing*/
	isCenter1 = false;
	isCenter2 = false;
	isCenter3 = false;
	/*Necessary conditions for center one to be chosen. (isCenter1 is a boolean)*/
	isCenter1 = ((strcmp(center1.city, city) == ZERO) && (center1.price <= maxPrice) && ((center1.price <= center2.price)&&(center1.price <= center3.price)));
	
		if (isCenter1){
	
			strcpy (bestCenter.name, center1.name);
			strcpy (bestCenter.city, center1.city);
			bestCenter.category = center1.category;
			bestCenter.centerType = center1.centerType;
			bestCenter.price = center1.price;
		
			
		} else{
			
			/*Necessary conditions for center two to be chosen. (isCenter2 is a boolean)*/
			isCenter2 = ((strcmp(center2.city, city) == ZERO) && (center2.price <= maxPrice) && ((center2.price < center1.price) || (center2.price < center3.price)));
			
				if (isCenter2) {
				
					strcpy(bestCenter.name, center2.name);
					strcpy(bestCenter.city, center2.city);
					bestCenter.category = center2.category;
					bestCenter.centerType = center2.centerType;
					bestCenter.price = center2.price;	
			
			
				}else{
				
					/*Necessary conditions for center tree to be chosen. (isCenter3 is a boolean)*/
					isCenter3 = ((strcmp(center3.city, city) == 0) && (center3.price <= maxPrice) && ((center3.price < center1.price) || (center3.price < center2.price)));
				
						if (isCenter3) {
				
							strcpy(bestCenter.name, center3.name);
							strcpy(bestCenter.city, center3.city);
							bestCenter.category = center3.category;
							bestCenter.centerType = center3.centerType;
							bestCenter.price = center3.price;
							
				
				}
			}
	
		}
		
		/*Exercise 2.4*/
		printf("RESULTS \n");
		
		/**/
		/*boolean var reuse*/
		if (isCenter1 || isCenter2 || isCenter3){
		
			printf("THE BEST CENTER IS:\n");
			printf("NAME: %s\n",bestCenter.name);
			printf("CITY: %s\n",bestCenter.city);
			printf("CATEGORY (1-CATEGORY1, 2-CATEGORY2, 3-CATEGORY3): %d\n",bestCenter.category);
			printf("CENTER TYPE (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST): %u\n",bestCenter.centerType);
			printf("PRICE EUR: %.2f\n", bestCenter.price);
				
	    }else{
		
			printf("THERE IS NO CENTER WITH THE DESIRED CONDITIONS\n");
	    
		}
	
	return 0;
}
