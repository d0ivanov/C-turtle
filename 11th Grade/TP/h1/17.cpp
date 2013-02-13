/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе число x, където x e интервала (0;1). Да се намери сумата от сбора на реципрочните стойности за всеки две twin primes. Развитието да продължи докато отношението не стане по-малко то x.
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int primeCheck(int n){
    int i;

    for (i = 2; i <= n; i++)
    {
        if (n % i == 0 && n != i ) {
            return 0;
        }
    }
    return 1;
}

int hasTwin(int prime){
    if (primeCheck(prime+2) > 0){
        return prime+2;
    }else if (primeCheck(prime-2) > 0){
        return prime-2;
    }else return 0;
}

int main(){
    float x;
    float lastSum = 1.0, floatI = 1.0;
    int i = 1;

    cout<< "Enter 0<x<1: " <<endl;
    do{
        cin>> x;
    }while(x <= 0 || x >= 1);

    cout<<endl;
    cout<<endl;

    while(lastSum >= x){
        i++;
        floatI = i;
        if (primeCheck(i)){
            if (hasTwin(i)>0){
                lastSum = (1/floatI) + (1/hasTwin(i));
                //sum += lastSum;
            }
        }
    }
    cout<< "Brun's constant is: ";
    cout<< lastSum <<endl;
    
    return 0;
}
