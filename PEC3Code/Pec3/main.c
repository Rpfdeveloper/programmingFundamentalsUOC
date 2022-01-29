/*
* File: main.c
* Author: Julio Roberto Pajuelo Ferreira
* Date: 10-10-2021
* Description: PEC3 Estructuras condicionales 
*/

#include <stdio.h>


/* Declaración de constantes en tiempo de compilación */
#define CENTER1 1
#define CENTER2 2
#define CENTER3 3
#define MAX_COWORKCENTERS 3
#define MIN_PRICE 0.0
#define MIN_DISCOUNT 0.0
#define MAX_DISCOUNT 50.0
#define MAX_COWORKERPERROOM 2
#define ZERO 0
#define ONE 1
#define TWO 2
#define PERCENT 100
#define REST 1;
/* definición de un tipo de dato enumerado*/
typedef enum {STARTUPS,FREELANCERS,RURAL,SPECIALICED,GENERALIST} tCoworkingType;



/*Función main*/
int main(int argc, char **argv)
{
	/*var declaration*/
	/*Exercise 2.1*/
	float price[MAX_COWORKCENTERS];
	/*Exercise 2.2*/
	float discount[MAX_COWORKCENTERS];
	float totalPrice[MAX_COWORKCENTERS];
	int numCoworkers;
	int bestCoworkCenter;
	int numSpaces;
	//Data input
	printf("INPUT DATA\n");
	printf("CENTER 1\n");
	printf("PRICE [EUR]? (A REAL) >>\n");
	scanf("%f",&price[ZERO]);
	printf("DISCOUNT [0.0%% - 50.0%%]? (A REAL) >>\n");
	scanf("%f",&discount[ZERO]);
	

	printf("CENTER 2\n");
	printf("PRICE [EUR]? (A REAL) >>\n");
	scanf("%f",&price[ONE]);
	printf("DISCOUNT [0.0%% - 50.0%%]? (A REAL) >>\n");
	scanf("%f",&discount[ONE]);
			

	printf("CENTER 3\n");
	printf("PRICE [EUR]? (A REAL) >>\n");
	scanf("%f",&price[TWO]);
	printf("DISCOUNT [0.0%% - 50.0%%]? (A REAL) >>\n");
	scanf("%f",&discount[TWO]);
	printf("COWORKERS? (AN INTEGER) >>\n");
	scanf("%d",&numCoworkers);
	/*Data validation*/
				
		
	if ((price[ZERO] < MIN_PRICE || discount[ZERO] < MIN_DISCOUNT || discount[ZERO] > MAX_DISCOUNT)||(price[ONE] < MIN_PRICE || discount[ONE] < MIN_DISCOUNT || discount[ONE] > MAX_DISCOUNT)||(price[TWO] < MIN_PRICE || discount[TWO] < MIN_DISCOUNT || discount[TWO] > MAX_DISCOUNT)){
	
		printf("INVALID DATA. TRY AGAIN!\n");	
	}
		else{
					
						
		/*Data procesing*/
		/*Exercise 2.4*/
		/*En este paso usando un booleano como en el anterior ejercicio ahorraría código pero implemento una estructura condicional 
		* ya que es el tema en el que nos encontramos*/
			if(numCoworkers%MAX_COWORKERPERROOM != ZERO){
				numSpaces = (numCoworkers/MAX_COWORKERPERROOM)+REST;
							totalPrice[ZERO] = ((price[ZERO]-((price[ZERO]*discount[ZERO])/PERCENT))*numSpaces);
							totalPrice[ONE]= ((price[ONE]-((price[ONE]*discount[ONE])/PERCENT))*numSpaces);
							totalPrice[TWO]= ((price[TWO]-((price[TWO]*discount[TWO])/PERCENT))*numSpaces);
						
						}
						else{
						
							numSpaces = (numCoworkers/MAX_COWORKERPERROOM);
							totalPrice[ZERO] = ((price[ZERO]-((price[ZERO]*discount[ZERO])/PERCENT))*numSpaces);
							totalPrice[ONE]= ((price[ONE]-((price[ONE]*discount[ONE])/PERCENT))*numSpaces);
							totalPrice[TWO]= ((price[TWO]-((price[TWO]*discount[TWO])/PERCENT))*numSpaces);
							
						}
							/*Aqui hago las comparacciones necesarias para saber cual de los precios es el 
							 * mejor con respecto a su precio teniendo en cuenta los enpates de todos o dos de ellos cualquiera*/
							
							if(totalPrice[ZERO] <= totalPrice[ONE] && totalPrice[ZERO] <= totalPrice[TWO]){
								bestCoworkCenter = CENTER1;
							}
							else{
								if(totalPrice[ONE] < totalPrice[ZERO] && totalPrice[ONE] < totalPrice[TWO]){
									bestCoworkCenter = CENTER2;
								}
								else{
									if(totalPrice[TWO] < totalPrice[ONE] && totalPrice[TWO] < totalPrice[ZERO]){
										bestCoworkCenter = CENTER3;
									}
								}
												
							}
							
							/*Prioridad entre iguales*/
							if((totalPrice[ZERO] == totalPrice[ONE] && totalPrice[ZERO] < totalPrice[TWO])||(totalPrice[ONE] == totalPrice[TWO] && totalPrice[ZERO] < totalPrice[ONE])||(totalPrice[ZERO] == totalPrice[TWO] && totalPrice[ZERO]<totalPrice[ONE])){
								bestCoworkCenter = CENTER1;
							}
							else{
								if(totalPrice[ZERO] == totalPrice[ONE] && totalPrice[ZERO] > totalPrice[TWO]){
									bestCoworkCenter = CENTER3;
														
								}
								else{
									if((totalPrice[ONE] == totalPrice[TWO] && totalPrice[ZERO] > totalPrice[ONE])||(totalPrice[ZERO] == totalPrice[TWO] && totalPrice[ZERO]>totalPrice[ONE])){
										bestCoworkCenter = CENTER2;
									}
									
								}
																
							}
														
												
										
										
					/*Data output*/
					/*Exercise 2.5*/
					
		printf("RESULTS\n");
		printf("CHEAPEST COWORK CENTER:");
		printf("%d\n",bestCoworkCenter);	
			if(bestCoworkCenter == CENTER1){
				printf("MONTHLY PRICE: ");
				printf("%.2f\n",totalPrice[ZERO]);
			}
			 else{
				if(bestCoworkCenter == CENTER2){
					printf("MONTHLY PRICE: ");
					printf("%.2f\n",totalPrice[ONE]);
				}
				 else{
					printf("MONTHLY PRICE: ");
					printf("%.2f\n",totalPrice[TWO]);
				}
			}				
										
					
				
		}
				
			
		return 0;
}

				
				
		
		
								

							
	
							
				
							

