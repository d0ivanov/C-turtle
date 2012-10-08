/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число x, където 0<x<10. Да се инициализира масив от 100 целочислени елемента. Стойностите на елементите да са случайни числа в интервала [0, 100). Елементите на масива да се подредят така, че числата завършващи на x да са в началото.
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

void swap( int *a, int *b )
{
    float temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int arr[], int lastNum){
    for (int i = 0; i < 100; i++)
        {
              for (int j = 0; j < 99; j++)
              {
                   if( ((arr[j+1] - lastNum) % 10) == 0)
                        swap(&arr[j], &arr[j+1]);
              }
        }
}

int main(){
    int x;

    int i;

    srand(13);
    cout<< "Enter 0<x<10: " <<endl;
    do{
        cin>> x;
    }while(x <= 0 || x >= 10);

    cout<<endl;
    cout<<endl;

    int array[100];

    for (i = 0; i < 100; i++){
        array[i] = rand() % 100;
        cout<< array[i] <<endl;
    }

    cout<<endl;
    cout<<endl;

    for (i = 0; i < 100; i++){
        sortArray(array, x);
        cout<< array[i] <<endl;
    }
    
    return 0;
}
