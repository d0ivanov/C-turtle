/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. Да се намерят и изведат всички числа на Фибоначи в интервала [x, y].
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){
    int x, y;

    int container, fib1 = 0, fib2 = 1;

    cout<< "Enter x: "<<endl;
    cin>> x;
    cout<<"\nEnter y > x: "<< endl;
    do{
        cin>> y;
    }while(y <= x);

    cout<<endl;

    while(1){
        container = fib2;
        fib2 += fib1;
        fib1 = container;
        if (fib1 == fib2 && fib1 >= x){
            cout<< fib1 <<endl;
        }
        if(fib2 >= x && fib2<y){
             cout<<fib2<<endl;
        }
        if(fib2 > y){
            return 0;
        }
    }
}

