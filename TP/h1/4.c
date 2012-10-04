/*
Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. 
Да се намерят и изведат всички числа на Фибоначи в интервала [x, y].
*/
#include <stdio.h>

//#define DEBUG

/* Returns the N-th fibunacci number.
 * @arg int the fibunacci number to find
 * @return int
 */
int fibunacci( int );

void main(){
	int x, y, i, fib, n = 0;

	printf("Vuvedi x: ");
	scanf("%d", &x);
	printf("\n");

	do{
		printf("Vuvedi y: ");
		scanf("%d", &y);
		printf("\n");
		if( x > y ){
			printf("x trqbva da e < y\n");		
		}
	}while( x >= y );
	
	for( i = x; i <= y || fib > y; i++ ){
		fib = fibunacci(n);		
		n++;
		if( fib >= x && fib <= y ){
			printf("%d\n", fib);		
		}
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
