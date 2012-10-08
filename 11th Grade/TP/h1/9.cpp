/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе число x, където 0<x<1. Да се намери числото пи чрез следното развитие в ред:
4-4/3+4/5-4/7+4/9-4/11+...4/N. Развитието в ред спира при 4/N<x. Получената стойност за пи да се изведе на екрана.
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){
    double x;

        cout<< "Enter 0<x<1: " <<endl;
        do{
            cin>> x;
        }while(x <= 0 || x >= 1);

        cout<<endl;
        cout<<endl;

        double pi = 4.0, n = 3.0;
        bool boolean = false; // false - negative, true - positive

        while (4/n >= x){
            if (boolean){
                pi += 4/n;
            }else{
                pi -= 4/n;
            }
            n++;
            boolean = !boolean;
        }
        cout<< pi <<endl;
	
	return 0;
}
