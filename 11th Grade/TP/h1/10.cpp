/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма,  която изисква от потребителя да въведе четири числа x, y, w, h където x>0, y>0, w>0, h>0. Числото x е дължината на плоча дървесина, а числото y е височината. Да се определи на колко цели плочи с размери w, h може да се разреже голямата плоча. Да се инициализира масив от 10 елемента. Стойностите на елементите на масива да са първите 10 координати по дължина на плочата, в които тя трябва да се разреже, за да се получат по-малките плочи.
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int main(){
    int x, y, w, h, array[10], plates, slices;
    
    cout<< "Enter x>0: " <<endl;
        do{
            cin>> x;
        }while(x <= 0);

        cout<<endl;
        cout<< "Enter y>0: " <<endl;
        do{
            cin>> y;
        }while(x <= 0);

        cout<<endl;
        cout<< "Enter w>0: " <<endl;
        do{
            cin>> w;
        }while(x <= 0);

        cout<<endl;
        cout<< "Enter h>0: " <<endl;
        do{
            cin>> h;
        }while(x <= 0);

        cout<<endl;
        cout<<endl;

    if (w > x || h > y){
        cout<<"XY can be sliced to 0 WH plates." <<endl;
        return 42;
    }

    if (x == w){
        cout<< "You don't have to slice it."<<endl;
        return 42;
    }

    slices = x/w;
    if (y/h < slices){
        slices = y/h;
    }

    plates = (x/w) * (y/h);
    cout<< "You have ";
    cout<< plates;
    cout<< " plates.\nSlices on X should be put on coordinates:" <<endl;

    int i2 = 0;
    for (int i = 0; i < slices; i++){
        if (i != 0){
            i2 = i+1;
        }else{
            i2++;
        }
        array[i] = i2*w;
        if (i == 9){
            break;
        }
    }

    for (int i = 0; i < slices; i++){
        cout<< array[i] <<endl;
        if (i == 9){
            break;
        }
    }

	return 0;
}

