/*
#school - TUES
#class - 11B
#num - 15
#name - Dobromir Ivanov
#task - Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. Да се намери и изведе сумата на числата делящи се на 17 в интервал [x, y].
*/
#include <stdio.h>

//#define DEBUG

const DEVISER = 17;

/* Checks if integer is devidable by
 * X. Where X is also an integer
 * @arg int integer to check
 * @arg int the integer to devide by
 * @return int
 */
int isDevidable(int, int);

/* Calculates the sum of all devidable numbers in an interval.
 * @arg int the begining of the interval.
 * @arg int the end of the interval. 
 * @return int.
*/
int getTotal(int, int);

void main(){
	int x, y, i, total;

	printf("Vuvedi x: ");
	scanf("%d", &x);
	printf("\n");

	do{
		printf("Vuvedi y: ");
		scanf("%d", &y);
		printf("\n");
		if( x >= y ){
			printf("x trqbva da e < y\n");		
		}
	}while( x > y );

	total = getTotal(x, y);
	printf("Rezultat: %d\n", total);	
}

int isDevidable(int i, int x){
	if( i % x == 0 ){
		return 1;
	}
	return 0;
}

int getTotal(int x, int y){
	int i, sum = 0;

	for( i = x; i <= y; i++ ){
		if( isDevidable(i, DEVISER) ){		
			sum += i;
			
			#ifdef DEBUG
				printf("[DEBUG] i = %d\n", i);
			#endif
		}
	}
	return sum;
}
