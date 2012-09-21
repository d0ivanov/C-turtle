/*
Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<=x<10. Да се инициализира масив от 10 елемента. Да се намерят първите 10 числа на Фибоначи в [0; +∞), които се делят на x без остатък. Намерените стойности да се зададат като стойности на елементите в масива. Елементите на масива да се изведат на стандартния изход.
*/
#include<stdio.h>

const MAX_ARR = 10;

int fibunacci( int n );

void fillArray( int arr[], int max, int x );

void printArr( int arr[], int max );

void main(){
	int x, arr[MAX_ARR];	
	do{
		printf("x=");
		scanf("%d", &x);
	}while( x < 0 || x >= 10 );
	fillArray(arr, MAX_ARR, x);
	printArr( arr, MAX_ARR );
}

int fibunacci( int n ){
	int first = 0, second = 1, i, next;
	if (n == 1 )
    {
      return first;
    }
	if( n == 2 ){
		return second;	
	}
	for( i = 0; i < n-2; i++ ){
		next = first + second;
		first = second;
		second = next;
	}
	return next;
}

void fillArray( int arr[], int max, int x ){
	int i, n = 2, fib;
	for( i = 0; i < max; i++ ){
		do{		
			fib = fibunacci(n);
			n++;		
			if(!(fib % x)){
				arr[i] = fib;
			}
		}while( fib % x );
	}
}

void printArr( int arr[], int max ){
	int i;	
	for( i = 0; i < max; i++ ){
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}
