/*
* File: main.c
* Author: Julio Roberto Pajuelo Ferreira
* Date: 25-09-2021
* Description: PEC2 Expresiones 
*/

#include <stdio.h>
#include <stdbool.h>

/* Declaración de constantes en tiempo de compilación */
#define CATEGORY1 1
#define CATEGORY2 2
#define CATEGORY3 3
#define MAXDISTANCETOCENTER 5
#define MAXPRICE 100
#define OCCUPATIONCAMPAING 50.00
#define MAXCOWORKERPERROOM 2
#define ZERO 0;

/* definición de un tipo de dato enumerado*/
typedef enum {STARTUPS,FREELANCERS,RURAL,SPECIALICED,GENERALIST} tCoworkingType;



/*Función main*/
int main(int argc, char **argv)
{
	int id;
	int category;	
	int coworkers;
	int intToBoolHasKitchen;
	int intToBoolHasAudithorium;
	float price;
	float distanceFromCityCenter;
	float percentOccupation;
	float totalPrice;
	float discount;
	bool hasMeetingRooms;
	bool hasKitchen;
	bool hasAudithorium;
	bool isOptimal;
	bool isAdvertisingCampaign;
	bool rest;
	tCoworkingType coworkingType;	

	printf("INPUT DATA\n");
	printf("ID?(AN INTEGER) >>\n");
	scanf("%d",&id);
	printf("TYPE?(1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST) >>\n");
	scanf("%u",&coworkingType);
	printf("CATEGORY?(AN INTEGER) >>\n");
	scanf("%d",&category);
	printf("PRICE[EUR]?(A REAL) >>\n");
	scanf("%f",&price);
	printf("DISTANCE FROM CITY CENTER[KM]?(A REAL) >>\n");
	scanf("%f",&distanceFromCityCenter);
	printf("HAS KITCHEN? (0-FALSE, 1-TRUE) >>\n");
	scanf("%d",&intToBoolHasKitchen);
	hasKitchen = (bool)intToBoolHasKitchen;
	printf("HAS AUDITORIUM? (0-FALSE, 1-TRUE) >>\n");
	scanf("%d",&intToBoolHasAudithorium);
	hasAudithorium = (bool)intToBoolHasAudithorium;
	printf("OCCUPATION [PERCENT]? (A REAL) >>\n");
	scanf("%f",&percentOccupation);
	printf("COWORKERS? (AN INTEGER) >>\n");
	scanf("%d",&coworkers);
	printf("DISCOUNT [PERCENT]? (A REAL) >>\n");
	scanf("%f",&discount);

	/*data procesing*/
	/*Exercise 2.3*/

	isOptimal = (distanceFromCityCenter < MAXDISTANCETOCENTER && price <= MAXPRICE && hasKitchen);

	/*Exercise 2.4*/

	isAdvertisingCampaign = (percentOccupation < OCCUPATIONCAMPAING && distanceFromCityCenter >= MAXDISTANCETOCENTER);

	/*Exercise 2.5*/

	rest = coworkers%MAXCOWORKERPERROOM != ZERO;
	totalPrice = ((price - ((price * discount)/100))* ((coworkers/MAXCOWORKERPERROOM)+rest));

	/*Exercise 2.6*/

	printf("RESULTS\n");
	printf("IS ACCEPTABLE(0-FALSE, 1-TRUE): %d \n",isOptimal);
	printf("NEEDS PROMOTION (0-FALSE, 1-TRUE): %d \n",isAdvertisingCampaign);
	printf("MONTHLY PRICE [EUR]: %.2f ",totalPrice);


	return 0;
}
