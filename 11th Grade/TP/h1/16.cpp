/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където x e интервала [0; +∞). Да се намерят първите 10 нечетни числа делители на x и да се запишат в масив. Масивът да се изведе на екрана и да се намерят простите числа в този масив.
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

int oddCheck(int n){
    if (n % 2 != 0) {
        return 1;
    }
    return 0;
}

int main(){
    int x;
    int i, j = 0, array[10];

    cout<< "Enter x>0: " <<endl;
    do{
        cin>> x;
    }while(x <= 0);

    cout<<endl;
    cout<<endl;

    for(i = 1; j < 10; i++){
        if (oddCheck(i) && (x % i) == 0){
            array[j] = i;
            cout<< array[j] <<endl;
            j++;
        }
        if (i >= x) {
            break;
        }
    }

    cout<< endl;
    cout<< "Primes: " <<endl;

    for (i = 0; i < j; i++){
        if (primeCheck(array[i])){
            cout<< array[i] <<endl;
        }
    }
    
    return 0;
}
