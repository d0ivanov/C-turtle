/*
 Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. 
 Да се намерят и изведат всички прости числа завършващи на 3 в интервал [x,y].
*/
#include <stdio.h>

const END = 3;

/* Checks if number ends with another number. Returns
 * 1 if true.
 * @arg int integer to check
 * @arg int integer to check against
 * @return int
 */
int endsWith(int, int);

/* Checks if number is simple
 * @arg int integer to check. 
 * @return int.
 */
int isPrime(unsigned int);

/* Prints all numbers in an interval that
 * meet the conditions set by two functions
 * @arg int begining of interval
 * @arg int end of interval
 * @return void
 */
void printNumbers( int, int );

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
	printNumbers(x, y);
	
}

int endsWith(int i, int x){
	if( i % 10 == x ){
		return 1;
	}
	return 0;
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

void printNumbers( int x, int y ){
	int i;
	for( i = x; i <= y; i++ ){
		if( isPrime(i) ){
			if(endsWith(i, END)){
				printf("%d\n", i);
			}
		}
	}
}
