/*
#school - TUES
#class - 11B
#num - 15
#name - Dobromir Ivanov
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<=x<10. Да се инициализира масив от 10 елемента. Да се намерят първите 10 числа на Фибоначи в [0; +∞), които се делят на x без остатък. Намерените стойности да се зададат като стойности на елементите в масива. Елементите на масива да се изведат на стандартния изход.
*/
#include<stdio.h>

const MAX_ARR = 10;

	/*
	 * Finds the N-th fibunacci number.
	 * @arg int n fibunacci number to find.
	 * @return int fibunacci number
	 */
int fibunacci( int n );

	/*
	 * Fills the array.
	 * @arg int arr[] the array to fill.
	 * @arg int max array size.
	 * @arg int x devisor.
	 * @return void
	 */
void fillArray( int arr[], int max, int x );

	/*
	 * Prints an array.
	 * @arg int arr[] array to print.
	 * @arg int max array size.
	 */
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
