/*
#school - TUES
#class - 11B
#num - 15
#name - Dobromir Ivanov
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число, x, където 0 < x < 10. Да се инициализират масива от 10 елемента. Стойностите на елементите на масива да са равни на косинус от индекса на елемента. Да се изведе масивът, след което да се сортира в низходящ ред и отново да се изведе
*/
#include<stdio.h>
#include<math.h>

enum bool {FALSE, TRUE};
	/*
	 * Fill an array with random numbers
	 * @arg array[] array to be filled
	 * @arg max elements in the array
	 */
void fillArray(double arr[], int max);
	
	/*
	 * Prints an array.
	 * @arg int n size of array.
	 * @arg 
	 */
void printArray( int n, double arr[] );

	/*
	 *	Comparison for descending sort
	 *	@arg int first number to compare
	 *	@arg int second number to compare
	 *	@return 0 if first > second number
	 */
int desc( double a, double b);

	/*
	 *	Comparison for ascending sort
	 *	@arg int first number to compare
	 *	@arg int second number to compare
	 *	@return 1 if first > second number
	 */
int asc( double a, double b);


	/*
	 *	Swap values of two variables
	 *	@arg pointer to 1st value to be swapped
	 *	@arg pointer to 2nd value to be swapped
	 */
void swap( double *a, double *b );

	/*
	 *	Sort an array by the bubble method
	 *	@arg int arr[] array to be sorted
	 *	@arg ptr order ascending or descending ordering
	 *	@arg int max elements in the array
	 */
void bubbleSort(double arr[], int(*order)(double, double), int max);

void main(){
	int x;
	double arr[10];	
	do{
		printf("x=");
		scanf("%d", &x);
	}while( x <= 0 && x >= 10 );
	fillArray(arr, x);
	printf("Before sorting\n");
	printArray(x, arr);
	bubbleSort( arr, desc, x );
	printf("After soritng\n");
	printArray(x, arr);
}

void fillArray(double arr[], int max){
	int i;
	double index = 0.00f;
	for(i = 0; i < max; i++){
		arr[i] = cos(index);
		index++;
	}
}

void printArray( int n, double arr[] ){
	int i;
	for( i = 0; i < n; i++ ){
		printf("Array[%d] = %f\n", i, arr[i]);
	}
}

int desc( double a, double b)
{
	if(a > b)
	{
		return 0;
	}
	return 1;
}

int asc( double a, double b)
{
	if( a > b )
	{
		return 1;
	}
	return 0;
}

	/*
	 *	Swap values of two variables
	 *	@arg pointer to 1st value to be swapped
	 *	@arg pointer to 2nd value to be swapped
	 */
void swap(  double *a, double *b )
{
	double temp;

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
void bubbleSort(double arr[], int(*order)(double, double), int max)
{
	int swaped = FALSE, i, j;

	while(!swaped)
	{
		swaped = TRUE;
		for(i = 0; i < max; i++)
		{
			if( order(arr[i], arr[i+1]) )
			{
				swap(&arr[i], &arr[i+1]);
				swaped = FALSE;
			}
		}
		max -= 1;
	}	
}
