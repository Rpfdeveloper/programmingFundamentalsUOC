/*
* File: main.c
* Author: UOC and Julio Roberto Pajuelo Ferreira
* Course: 20211
* Description: PAC8-PEC8-CAA8
*/
#include <stdio.h>
#include "coworkingcenter.h"

int main(int argc, char **argv)
{
	tCoworkingCentersTable centersTable;
	char filename[MAX_NAME];	
	bool isRead = false;
	char city[MAX_CITY];
	float optimalDistance;
	float optimalPrice;
	float neededPoints;
	float averageCenters = 0.0;
	tCoworkingCentersTable newTCenter;
	int i;
	
	/* Exercise 2.4 */
	/* centerTable initialization */
    centersTableInitialize(&centersTable);   

	 /* load data from file */ 
    printf("LOAD DATA FROM FILE. ENTER FILE NAME >>\n");
    scanf("%s",filename);    
	centersTableLoadDataFromFile(&centersTable,filename,&isRead);
	
	if (isRead) {	
		printf("CENTER TABLE SUCCESSFULLY LOADED\n");	
		/* Data input */	
		printf("CITY NAME (A STRING)? >>\n");
		scanf("%s",city);
		printf("OPTIMAL DISTANCE [KM]? >>\n");
		scanf("%f",&optimalDistance);
		printf("OPTIMAL PRICE [EUR]? >>\n");
		scanf("%f",&optimalPrice);
		printf("NEEDED POINTS (A REAL)? >>\n");
		scanf("%f",&neededPoints);
		
		centersTableSelect(centersTable,city,optimalDistance,optimalPrice,neededPoints,&newTCenter);
		
		
		
		/* Exercise 2.5 */
		printf("RESULTS\n");
		
		if(newTCenter.numCenters != ZERO){
			
			printf("CENTERS FOUND: %d\n",newTCenter.numCenters);
			printf("SELECTED CENTERS:\n");
			
			for(i = 0; i < newTCenter.numCenters;i++){
				
				writeCenter(newTCenter.centers[i]);
			
			}
		
		}else{
			
			printf("NO AVAILABLE CENTERS WITH THIS CRITERION\n");
		}
		
		averageCenters = centersAverageOccupation(centersTable,city);
		printf("MEAN PERCENTAGE OCCUPATION FOR THE CITY OF %s IS %.2f\n",city,averageCenters);
	}
	
	return 0;	
}
