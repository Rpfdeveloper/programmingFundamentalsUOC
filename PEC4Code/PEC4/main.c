/*
* File: main.c
* Author: Julio Roberto Pajuelo Ferreira
* Date: 12-10-2021
* Description: Estructuras iterativas 
*/

/* Constant declaration */
#include <stdio.h>
#include <stdbool.h>
#define MIN_COWORKCENTERS 1
#define MAX_COWORKCENTERS 5
#define MAX_DISTANCE 5.0
#define MAX_PRICE 100.0
#define ZERO 0
/*typedef definition*/
typedef enum {STARTUPS,FREELANCERS,RURAL,SPECIALICED,GENERALIST} tCoworkingType;

/*funtion main*/

int main(int argc, char **argv)
{
/*var declaration*/
int  coworkCenterIdVector[MAX_COWORKCENTERS];
tCoworkingType coworkTypeVector[MAX_COWORKCENTERS];
float priceVector[MAX_COWORKCENTERS];
float distanceFromCityCenterVector[MAX_COWORKCENTERS];
bool hasKitchenVector[MAX_COWORKCENTERS];
int hasKitchenInToBool;
int acceptableCoworkCenters[MAX_COWORKCENTERS];
int numCoworkCenters;
int numAcceptableCoworkCenters;
int i;
int j;
int w;
tCoworkingType coworkType;

/*Data imput*/
/*Exercise 2.1*/
printf("INPUT DATA\n");

/*Data validation*/
w = ZERO;
while(numCoworkCenters<MIN_COWORKCENTERS || numCoworkCenters > MAX_COWORKCENTERS) {
	if(w != ZERO){
		printf("INVALID DATA, TRY AGAIN!\n");
	}
	printf("NUMBER OF COWORK CENTERS ? (1-5) >>\n");
	
scanf("%d",&numCoworkCenters);	
w++;
}

/*Exercise 2.2*/
i=ZERO;
for (i = ZERO;i < (numCoworkCenters); i++){
	printf("CENTER #%d\n",i+1);
	printf("ID?(AN INTEGER)>>\n");
	scanf("%d",&coworkCenterIdVector[i]);	
	printf("TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST)>>\n");
	scanf("%u",&coworkTypeVector[i]);
	printf("PRICE [EUR]?(A REAL)>>\n");
	scanf("%f",&priceVector[i]);
	printf("DISTANCE FROM CITY CENTER [KM]?(A REAL)>>\n");
	scanf("%f",&distanceFromCityCenterVector[i]);
	printf("HAS KITCHEN?(0-FALSE, 1-TRUE)>>\n");
	scanf("%d",&hasKitchenInToBool);
	hasKitchenVector[i]= hasKitchenInToBool;
	
}


/*Exercise 2.3*/
	printf("LOOKING FOR CENTERS\n");
	printf("TYPE? (1-STARTUPS, 2-FREELANCERS, 3-RURAL, 4-SPECIALIZED, 5-GENERALIST)>>\n");
	scanf("%u",&coworkType);
	
	/*Data processing*/	
	/*Exercise 2.4*/
	printf("RESULTS\n");
	i=ZERO;
	j=ZERO;
	numAcceptableCoworkCenters=0;
	for(i=ZERO;i<numCoworkCenters;i++){
		if(coworkTypeVector[i] == coworkType && distanceFromCityCenterVector[i]< MAX_DISTANCE && priceVector[i] <= MAX_PRICE && hasKitchenVector[i]){
		
			acceptableCoworkCenters[j] = coworkCenterIdVector[i];
		
			j++;
			numAcceptableCoworkCenters++;
		
		}
	}	
	/*Data output*/
	/*Exercise 2.5*/
	if(numAcceptableCoworkCenters != ZERO){

		printf("NUMBER OF ACCEPTABLE CENTERS: %d\n",numAcceptableCoworkCenters);
		i = ZERO;
		for(i = ZERO;i < numAcceptableCoworkCenters;i++){
		
			printf("CENTER ID: %d\n",acceptableCoworkCenters[i]);
		}
	}else{
		printf("THERE ARE NO ACCEPTABLE CENTERS.\n");
	}

	return 0;
}
