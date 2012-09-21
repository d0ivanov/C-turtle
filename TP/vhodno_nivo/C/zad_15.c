/*Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10. Да се инициализира масив от 10 елемента. Да се намери първото число на Фибоначи в интервала [0; +∞) завършващо на x и да се запише като първи елемент в масива. Да се намери второто число на Фибоначи в интервала [0;  +∞) завършващо на x и да се запише като втори елемент в масива. Аналогично да се намерят първите N прости числа в интервала [0;  +∞) и да се запишат като елемент N в масива. Масивът да се изведе на стандартния изход.*/
#include<stdio.h>

//#define DEBUG

const MAX_ARR = 10;

	/* Prints anarray
	 * @arg double arr the array to print
	 * @arg int max array size
	 * @arg x end of interval
	*/
void fillArray(int arr[], int max, int x);

void printArr( int arr[], int max );

int fibunacci( int n );

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
	int i, n, beginning = 0, num;
	for(i = 0; i < max; i++){
		for( n = beginning; ;n++ ){
			num = fibunacci(n);
			if(num%10 == x){
				beginning = n+1;
				break;
			}
		}
		arr[i] = num;
	}
}

void printArr( int arr[], int max ){
	int i;
	for( i = 0; i < max; i++ ){
		printf("Arr[%d] = %d\n", i, arr[i]);	
	}
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
