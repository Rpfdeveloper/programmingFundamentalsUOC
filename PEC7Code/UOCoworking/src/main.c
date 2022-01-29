/*
* File: main.c
* Author: Julio Roberto Pajuelo Ferreira
* Date: 09-11-2021
* Description: funtion main 
*/

/*include headboard*/
#include "UOCoworking.h"

tCoworkingCenter center1;
tCoworkingCenter center2;
tCoworkingCenter bestCenter;
int main(int argc, char **argv)
{

/*Exercise 2.3*/
/*Data imput and proccesing*/
readCenter(&center1);
readCenter(&center2);
copyCenter(cmpPointsCenter(center1,center2),&bestCenter);

/*Data ouput*/
printf("RESULT\n");
printf("THE BEST CHOICE IS:\n");
writeCenter(bestCenter);
}
