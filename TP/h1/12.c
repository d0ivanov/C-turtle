/*Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10. Да се инициализира масив от 10 елемента. Да се намери първото число N в интервала [0; +∞) делящо се на х. Да се намери сумата на всички числа в интервала [0; N] и да се запише като първи елемент в масива. Да се намери второто число N' в интервала [0; +∞) делящо се на x. Да се намери сумата на всички числа в интервала [0, N'] и да се запише като втори елемент в масива. Аналогично да се запълнят и останалите елементи на масива. Масивът да се изведе на стандартния изход.*/

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
		for( i = beginning+1; ;i++ ){
			if( i % x == 0 ){
				beginning = i;
				for( i = 0; i <= beginning; i++ ){
					sum += i;
				}
				break;
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
