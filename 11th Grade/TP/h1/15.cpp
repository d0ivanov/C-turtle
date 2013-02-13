/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10. Да се инициализира масив от 10 елемента. Да се намери първото число на Фибоначи в интервала [0; +∞) завършващо на x и да се запише като първи елемент в масива. Да се намери второто число на Фибоначи в интервала [0;  +∞) завършващо на x и да се запише като втори елемент в масива. Аналогично да се намерят първите N прости числа в интервала [0;  +∞) и да се запишат като елемент N в масива. Масивът да се изведе на стандартния изход.
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){
    int x;
    long long int array[10], fib1 = 0, fib2 = 1, container;
    int count = 0;

    cout<< "Enter 0<x<10: " <<endl;
    do{
        cin>> x;
    }while(x <= 0 || x >= 10);

    cout<<endl;
    cout<<endl;

    while (count < 10) {
        if (fib1 % 10 == x){
            array[count] = fib1;
            cout<< array[count++] << endl;
        }
        container = fib2;
        fib2 += fib1;
        fib1 = container;
    }
    
    return 0;
};
