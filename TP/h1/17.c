/*Да се разработи програма, която изисква от потребителя да въведе число x, където x e интервала (0;1). Да се намери сумата от сбора на реципрочните стойности за всеки две twin primes. Развитието да продължи докато отношението не стане по-малко то x.*/
#include<stdio.h>

double calcTwinPrimes(double x);

int isPrime(unsigned int number);

void main(){
	double x, sum;
	
	do{
		printf("x=");
		scanf("%lf", &x);
	}while( x > 1 || x <= 0 );
	sum = calcTwinPrimes(x);
	printf("sum=%f\n", sum);

}

double calcTwinPrimes(double x){
	int i;
	double sum = 0;
	for( i = 3; x >= sum; i+=2 ){
		if( isPrime(i) && isPrime(i+2) ){
			sum += (double)1/i + (double)1/(i+2);
			i+=2;
			#ifdef DEBUG
				printf("[DEBUG] i=%d\n", i);
				printf("[DEBUG] sum=%f\n", sum);
			#endif
		}
	}
	return sum;
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
