/*
#school - TUES
#class - 11B
#num - 15
#name - Dobromir Ivanov
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10. Да се инициализира масив от 10 елемента. Да се намери сумата от всички числа в интервала [0; 1000) делящи се на x и да се запише като първа стойност в масива. Да се намери сумата от всички числа в интервала [0;1000) деляща се на 2x и да се запише като втора стойност в масива. Аналогично да се намери сумата на всички числа делящи се на Nx за N в интервала [1;10] и да се запишат като елемент N-1 в масива. Масивът да се изведе на стандартния изход.*/
#include<stdio.h>

const MAX_ARR = 10;

	/* Prints anarray
	 * @arg double arr the array to print
	 * @arg int max array size
	 * @arg x end of interval
	*/
void fillArray(int arr[], int max, int x);

void printArr( int arr[], int max );

void main(){
	int arr[MAX_ARR], x;
	do{
		printf("x=");
		scanf("%d", &x);
	}while( x < 0 || x > 10 );
	
	fillArray(arr, MAX_ARR, x);
	printArr(arr, MAX_ARR);
}

void fillArray(int arr[], int max, int x){
	int i, n, sum, beginning = 0;
	for(n = 0; n < max; n++){
		sum = 0;
		for( i = 0; i < 1000;i++ ){
			if( i % (n+1)*x == 0 ){
				sum += i;
			}
		}
		arr[n] = sum;	
	}
}

void printArr( int arr[], int max ){
	int i;
	for( i = 0; i < max; i++ ){
		printf("Arr[%d] = %d\n", i, arr[i]);	
	}
}
