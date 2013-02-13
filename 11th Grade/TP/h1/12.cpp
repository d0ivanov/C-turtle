/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10. Да се инициализира масив от 10 елемента. Да се намери първото число N в интервала [0; +∞) делящо се на х. Да се намери сумата на всички числа в интервала [0; N] и да се запише като първи елемент в масива. Да се намери второто число N' в интервала [0; +∞) делящо се на x. Да се намери сумата на всички числа в интервала [0, N'] и да се запише като втори елемент в масива. Аналогично да се запълнят и останалите елементи на масива. Масивът да се изведе на стандартния изход. 
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int findN(int x, int lastN){

    while(1){
        lastN++;
        if (lastN % x == 0){
            return lastN;
        }
    }
}

int sumNumbers(int N){
    int sum = 0;

    for (int i = 0; i <= N; i++){
        sum += i;
    }
    return sum;
}

int main(){
    int x, N;

    int i;

    cout<< "Enter 0<x<10: " <<endl;
    do{
        cin>> x;
    }while(x <= 0 || x >= 10);

    cout<<endl;
    cout<<endl;

    int array[10], lastN = 0;

    for (i = 0; i < 10; i++){
        array[i] = sumNumbers(findN(x, lastN));
        lastN = findN(x, lastN);
        cout<< array[i] <<endl;
    }

    return 0;
}
