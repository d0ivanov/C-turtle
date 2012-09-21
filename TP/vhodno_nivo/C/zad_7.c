/*
Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<=x<10. Да се инициализира масив от 10 елемента. Да се намерят първите 10 стойности на функцията cos(x) в интервала [0; +∞), в които третата цифра след десетичната запетая е x. Пример при cos(1) = 0.540302306 третата цифра след десетичната запетая е 0. При cos(2) = -0.416146837 третата цифра след десетичната запетая е 6. Намерените стойности да се зададат като стойности на елементите в масива. Елементите на масива да се изведат на стандартния изход.
*/

const MAX_ARR = 10;

#include<stdio.h>
#include<math.h>

//#define DEBUG

void fillArray(double arr[], int max, int x);

void printArr( double arr[], int max );

int getThirdDigit( double number );

void main(){
	int x;
	double arr[MAX_ARR];

	do{
		printf("x=");
		scanf("%d", &x);
	}while( x < 0 || x >= 10 );

	fillArray(arr, MAX_ARR, x);
	printArr(arr, MAX_ARR);
}

int getThirdDigit( double number ){
	int in;				
	number *= 1000;
	in = (int) number;
	return in % 10;
}

void printArr( double arr[], int max ){
	int i;
	for( i = 0; i < max; i++ ){
		printf("Arr[%d] = %f\n", i, arr[i]);	
	}
}

void fillArray(double arr[], int max, int x){
	int i, in;
	double index = 0, cosVal, ip, number;
	for(i = 0; i < max; i++){
		do{
			cosVal = cos(index);
			index++;
			number = modf(cosVal, &ip);
			in = getThirdDigit( number );
		}while( cosVal < 0 || x != in );
		#ifdef DEBUG
			printf("%f\n -> %d\n", number, in);
		#endif		
		arr[i] = cosVal;
		
	}
}
