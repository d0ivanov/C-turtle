/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. Да се намери и изведе сумата на числата делящи се на 17 в интервал [x, y].
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){
    int x, y;

    int i, sum = 0;

    cout<< "Enter x: "<<endl;
    cin>> x;
    cout<<"\nEnter y > x: "<< endl;
    do{
        cin>> y;
    }while(y <= x);

    cout<<endl;

    for (i = x; i < y; i++){
        if (!(i % 17)){
            sum += i;
        }
    }
    cout<< sum <<endl;
    
    return 0;
}
