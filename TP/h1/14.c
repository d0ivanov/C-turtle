/*Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10. Да се инициализира масив от 10 елемента. Да се намери първото просто число в интервала [0; +∞) завършващо на x и да се запише като първи елемент в масива. Да се намери второто просто число в интервала [0;  +∞) завършващо на x и да се запише като втори елемент в масива. Аналогично да се намерят първите N прости числа в интервала [0;  +∞) и да се запишат като елемент N в масива. Масивът да се изведе на стандартния изход.*/
#include<stdio.h>

//#define DEBUG

const MAX_ARR = 10;

	/* Prints anarray
	 * @arg double arr the array to print
	 * @arg int max array size
	 * @arg x end of interval
	*/
int fillArray(int arr[], int max, int x);

void printArr( int arr[], int max );

int isPrime(unsigned int number);

void main(){
	int arr[MAX_ARR], x;
	do{
		printf("x=");
		scanf("%d", &x);
	}while( x < 0 || x > 10 );
	
	if(fillArray(arr, MAX_ARR, x)){
		printArr(arr, MAX_ARR);
	}
}

int fillArray(int arr[], int max, int x){
	int i, n, beginning = 0;
	if( x % 2 == 0 ) return 0;
	for(n = 0; n < max; n++){
		for( i = beginning; ;i++ ){
			if( isPrime(i) && i%10 == x ){
				beginning = i;
				break;
			}
		}
		arr[n] = beginning;
		#ifdef DEBUG
			printf("[DEBUG] arr[%d]=%d\n", n, beginning);	
		#endif
		beginning++;
	}
	return 1;
}

void printArr( int arr[], int max ){
	int i;
	for( i = 0; i < max; i++ ){
		printf("Arr[%d] = %d\n", i, arr[i]);	
	}
}

int isPrime(unsigned int number) {
	unsigned int i;
    if (number <= 1){
		 return 0;// zero and one are not prime
	} 
    for (i=2; i*i <= number; i++) {
        if (number % i == 0){
			return 0;
		}
    }
    return 1;
}
