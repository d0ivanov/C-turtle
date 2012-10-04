/*
#school - TUES
#class - 11B
#num - 15
#name - Dobromir Ivanov
#task - Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. 
Да се намери сумата на всички нечетни числа в интервала [x,y].
*/
#include <stdio.h>

/* Checks if number is even. Returns
 * 1 if integer is even.
 * @arg int integer to check
 * @return int
 */
int isEven(int);

/* Calculates the sum of all even numbers in an interval.
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

int isEven(int i){
	if( i % 2 == 0 ){
		return 1;
	}
	return 0;
}

int getTotal(int x, int y){
	int i, sum = 0;

	for( i = x; i <= y; i++ ){
		if( isEven(i) ){		
			sum += i;
		}
	}
	return sum;
}
