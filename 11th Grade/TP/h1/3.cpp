/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе две целочислени числа, x и y, където x < y. Да се намерят и изведат всички прости числа завършващи на 3 в интервал [x,y].
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int simpleCheck(int);
int threeCheck(int);

int main(){
	int x,y,i;

    cout<< "Enter x: "<<endl;
    cin>> x;
    cout<<"\nEnter y > x: "<< endl;
    do{
        cin>> y;
    }while(y <= x);

    cout<<endl;

    for (i = x; i <= y; i++){
        if (simpleCheck(i)){
            if (threeCheck(i))
            {
                cout<< i << endl;
            }
        }
    }
    
    return 0;
}

int threeCheck(int n){
    if ( (n - 3) % 10 == 0 || (n - 3) == 0) {
        return 1;
    }
    return 0;
}

int simpleCheck(int n){
    int i;

    for (i = 2; i <= n; i++)
    {
        if (n % i == 0 && n != i ) {
            return 0;
        }
    }
    return 1;
}
