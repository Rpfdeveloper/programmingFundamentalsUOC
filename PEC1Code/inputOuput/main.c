/*
* File: main.c
* Author: Julio Roberto Pajuelo Ferreira
* Date: 25-09-2021
* Description: Entrada y salida de datos 
*/




#include <stdio.h>
#include <stdbool.h>

				
// definición de un tipo de dato enumerado
		
typedef enum {STARTUPS,FREELANCERS,RURAL,SPECIALICED,GENERALIST} typeOfCenter;

//funcion main
int main(int argc, char **argv)
{
		
		//Declaracion de variables
		int id, quality, spaceForRent;
		float  rentalPricePerMonth, distanceToWorkCenter, percentageOfOccupation;
		bool kitchenRoom,auditorium;

		//Entrada de datos
		printf("INPUT DATA\n");
		printf("ID? (AN INTEGER) >>\n");
		scanf("%d",&id);
		printf("CATEGORY? (AN INTEGER) >>\n");
		scanf("%d",&quality);
		printf("SPACES? (AN INTEGER) >>\n");
		scanf("%d",&spaceForRent);
		printf("PRICE[EUR]? (A REAL) >>\n");
		scanf("%f",&rentalPricePerMonth);
		printf("DISTANCE FROM CITY CENTER [KM]? (A REAL) >>\n");
		scanf("%f",&distanceToWorkCenter);
		printf("OCCUPATION [PERCENT]? (A REAL) >>\n");
		scanf("%f",&percentageOfOccupation);
		
		//Salida de datos
		printf("RESULTS \n");
		printf("ID: %d", id);
		printf("\nCATEGORY: %d", quality);
		printf("\nSPACES: %d",spaceForRent);
		printf("\nPRICE [EUR]: %.2f",rentalPricePerMonth);
		printf("\nDISTANCE FROM CITY CENTER [KM]: %.2f",distanceToWorkCenter);
		printf("\nOCCUPATION [PERCENT]: %.2f\n",percentageOfOccupation);
		
	return 0;
}
