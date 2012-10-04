/*
#school - TUES
#class - 11B
#num - 15
#name - Dobromir Ivanov
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където x e интервала [0; +∞). Да се намерят първите 10 нечетни числа делители на x и да се запишат в масив. Масивът да се изведе на екрана и да се намерят простите числа в този масив.*/
#include<stdio.h>

const MAX_ARR = 10;

void fillArray( long int arr[], int max, int x );

void printArr( long int arr[], int max );

int isPrime(unsigned long int number);

void main(){
	int x; long int arr[MAX_ARR];
	
	do{
		printf("x=");
		scanf("%d", &x);
	}while( x <= 0 );
	fillArray( arr, MAX_ARR, x );
	printArr( arr, MAX_ARR );
}

void fillArray( long int arr[], int max, int x ){
	int i, n, beginning = 0, num;
	if( x%2 == 0 ) return;
	for( i = 0; i < max; i++ ){
		for( n = beginning; ; n++ ){
			if( ( n % 2 != 0 ) && ( n % x == 0 ) ){
				num = n;
				beginning = n+1;
				break;
			}
		}
		arr[i] = num;
	}
}

void printArr( long int arr[], int max ){
	int i;
	for( i = 0; i < max; i++ ){
		if( isPrime(arr[i]) ){
			printf("(prosto)arr[%d] = %lu\n", i, arr[i]);
		}else{
			printf("arr[%d] = %lu\n", i, arr[i]);		
		}

	}
}

int isPrime(unsigned long int number) {
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
