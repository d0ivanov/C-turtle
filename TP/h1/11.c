/*Да се разработи програма, която изисква от потребителя да въведе целочислено число х, където 0<x<10. Да се инициализира масив от 10 елемента. Да се намери сумата от cos(z) за всяко z в интервала [0;x) и да се запише като първи елемент в масива. Да се намери сумата от cos(z) за всяко z в интервала [x; 2x) и да се запише като втори елемент в масива. Аналогично да се намерят сумите на cos(z) за всички интервали [Nx; (N+1)x ) и да се запишат като елемент N в масива за всяко N в интервала [0, 10). Масивът да се изведе на стандартния изход.
*/
#include <stdio.h>
#include <math.h>

const MAX_ARR = 10;

	/* Prints anarray
	 * @arg double arr the array to print
	 * @arg int max array size
	 * @arg x end of interval
	*/
void fillArray(double arr[], int max, int x);

void printArr( double arr[], int max );

void main(){
	double arr[MAX_ARR];
	int x;
	
	do{
		printf("x=");
		scanf("%d", &x);
	}while( x < 0 || x > 10 );
	
	fillArray(arr, MAX_ARR, x);
	printArr(arr, MAX_ARR);
}

void fillArray(double arr[], int max, int x){
	int i, n;
	double cosVal;
	for(n = 0; n < max; n++){
		cosVal = 0;
		for( i = n*x; i < (n+1)*x; i++ ){
			cosVal += cos(i);
		}	
		arr[n] = cosVal;
		
	}
}

void printArr( double arr[], int max ){
	int i;
	for( i = 0; i < max; i++ ){
		printf("Arr[%d] = %f\n", i, arr[i]);	
	}
}
