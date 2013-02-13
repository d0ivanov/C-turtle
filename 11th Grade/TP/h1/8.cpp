/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<=x<10. Да се инициализира масив от 10 елемента. Да се намерят първите 10 числа на Фибоначи в [0; +∞), които се делят на x без остатък. Намерените стойности да се зададат като стойности на елементите в масива. Елементите на масива да се изведат на стандартния изход.
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){
    int x,i;

    cout<< "Enter 0<=x<10: " <<endl; // uslovieto na zadachata ne e spazeno zashtoto ne moje da se deli na 0... <_<
    do{
        cin>> x;
    }while(x < 0 || x >= 10);

    cout<<endl;
    cout<<endl;

    int array[10], fib1 = 1, fib2 = 1, container, foundCount;

    while (foundCount < 10){
        container = fib2;
        fib2 += fib1;
        fib1 = container;

        if (fib2 % x == 0){
            if(fib2 < 0) fib2 *= -1;
            array[foundCount] = fib2;
            foundCount++;
        }
    }

    cout<<endl;
    cout<<endl;

    for (i = 0; i < 10; i++){
        cout<< array[i] <<endl;
    }
    
    return 0;
}
