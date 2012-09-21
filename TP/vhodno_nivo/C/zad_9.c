/*
Да се разработи програма, която изисква от потребителя да въведе число x, където 0<x<1. Да се намери числото пи чрез следното развитие в ред:
4-4/3+4/5-4/7+4/9-4/11+...4/N. Развитието в ред спира при 4/N<x. Получената стойност за пи да се изведе на екрана.
*/

#include <stdio.h>

//#define DEBUG

double calcPi( float );

void main(){
	float x;
	
	do{
		printf("x=");
		scanf("%f", &x);
	}while( x > 0 && x > 1 );

	
	printf(" pi=%f\n ", calcPi(x));
}

double calcPi( float x ){
	int i, n = 1;
	double pi = 4.00f;

	for( i = 3; (float)4/i > x; i+=2 ){
		if( (n % 2) != 0 ){
			pi -= (double) 4/i;
		}else{
			pi += (double) 4/i;
		}
		#ifdef DEBUG
			printf("[DEBUG] pi=%f\n", pi);		
		#endif
		n++;
	}
	return pi;
}
