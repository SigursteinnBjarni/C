#include<stdio.h>

#define LOWER 0 /* Lower limit of the table */
#define UPPER_FAR 300 /* Upper limit of the far table */
#define UPPER_CEL 50 /* Upper limit of the cel table */

float calculate_cel(int degree)
{
	return  5.0 * (degree - 32) / 9.0;

}

short calculate_faren(int degree)
{
	return degree * (9.0 / 5.0) + 32;
}

int main()
{
	printf("Farenheit      Celcious\n");	
	for (int i = LOWER; i <= UPPER_FAR; i+=20){
		printf("%3d\t\t%.3f\n", i, calculate_cel(i));	
	}
	
	printf("\nCel\t\tFaren\n");	
	for (int i = LOWER; i <= UPPER_CEL; i+=5){
		printf("%3d\t\t%d\n", i, calculate_faren(i));	
	}
	return 0;
}
