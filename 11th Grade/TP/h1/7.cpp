/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<=x<10. Да се инициализира масив от 10 елемента. Да се намерят първите 10 стойности на функцията cos(x) в интервала [0; +∞), в които третата цифра след десетичната запетая е x. Пример при cos(1) = 0.540302306 третата цифра след десетичната запетая е 0. При cos(2) = -0.416146837 третата цифра след десетичната запетая е 6. Намерените стойности да се зададат като стойности на елементите в масива. Елементите на масива да се изведат на стандартния изход.
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int thirdDigitCheck(double dNum){
    int intNum;

    dNum *= 1000;
    intNum = (int) dNum;
    return intNum % 10;
}

int main(){
    int x;
    
    int i;

    cout<< "Enter 0<=x<10: " <<endl;
    do{
        cin>> x;
    }while(x < 0 || x >= 10);

    cout<<endl;
    cout<<endl;

    double array[10], i2;
    int foundCount = 0;

    while (foundCount < 10){
        if (thirdDigitCheck(cos(i2)) == x){
            array[foundCount] = cos(i2);
            foundCount++;
        }
        i2++;
    }

    cout<<endl;
    cout<<endl;

    for (i = 0; i < 10; i++){
        cout<< array[i] <<endl;
    }
        
	return 0;   
}
