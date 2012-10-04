/*
#school - TUES
#class - 11B
#num - 15
#name - Dobromir Ivanov
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено
число x, където 0<x<10. Да се инициализира масив от 100 целочислени елемента. 
Стойностите на елементите да са случайни числа в интервала [0, 100). 
Елементите на масива да се подредят така, че числата завършващи на x да са в началото.
*/
#include <stdio.h>
#include <stdlib.h>

enum bool{FALSE, TRUE};
const MAX_ARR = 100;
const MIN_RAND = 0;
const MAX_RAND = 100;

	/*
	 * Print an array.
	 * @arg array[] array to be filled
	 * @arg max elements in the array
	 */
void printArr( int arr[], int max );

	/*
	 * Fill an array with random numbers
	 * @arg array[] array to be filled
	 * @arg max elements in the array
	 */
void fillArray(int arr[], int max);

/* Checks if number ends with another number. Returns
 * 1 if true.
 * @arg int integer to check
 * @arg int integer to check against
 * @return int
 */
int endsWith(int, int);

	/*
	 *	Swap values of two variables
	 *	@arg pointer to 1st value to be swapped
	 *	@arg pointer to 2nd value to be swapped
	 */
void swap( int *a, int *b );

	/*
	 *	Sort an array by the bubble method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order ascending or descending ordering
	 *	@arg int max elements in the array
	 */
void bubbleSort(int arr[], int(*order)(int, int), int max, int x);

void main(){
	int x, arr[MAX_ARR];
	
	do{
		printf("x=");
		scanf("%d", &x);
		printf("\n");
	}while( x <= 0 || x >= 10 );
	fillArray(arr, MAX_ARR);
	bubbleSort(arr, endsWith, MAX_ARR, x);
	printArr(arr, MAX_ARR);
}

void printArr( int arr[], int max ){
	int i;
	for( i = 0; i < max; i++ ){
		printf("Arr[%d] = %d\n", i, arr[i]);	
	}
}

void fillArray(int arr[], int max){
	int i;
	for(i = 0; i < max; i++){
		arr[i] = MIN_RAND + rand() % (MIN_RAND - MAX_RAND);
	}
}

int endsWith(int i, int x){
	if( i % 10 == x ){
		return 1;
	}
	return 0;
}

	/*
	 *	Swap values of two variables
	 *	@arg pointer to 1st value to be swapped
	 *	@arg pointer to 2nd value to be swapped
	 */
void swap( int *a, int *b ){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

	/*
	 *	Sort an array by the bubble method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order ascending or descending ordering
	 *	@arg int max elements in the array
	 */
void bubbleSort(int arr[], int(*order)(int, int), int max, int x){
	int i, j, swaped;

	for( i = 0; i <= max; i++ ){
		swaped = FALSE; j = 0;
		if(order(arr[i], x)){
			while(!swaped){
				if( !order(arr[j], x) ){
					swap(&arr[j], &arr[i]);	
					swaped = TRUE;	
				}
				j++;
			}
		}
	}	
}
