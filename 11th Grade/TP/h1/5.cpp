/*
#school - ТУЕС
#class - 11Б
#num - 22
#name - Михаил Михайлов Здравков
#task - Да се разработи програма, която изисква от потребителя да въведе целочислено число, x, където 0 < x < 10. Да се инициализират масива от 10 елемента. Стойностите на елементите на масива да са равни на косинус от индекса на елемента. Да се изведе масивът, след което да се сортира в низходящ ред и отново да се изведе.
*/

#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

void swap( float *a, float *b );
void bubbleSort(float arr[], int n);

int main(){
    int x;
    int i;

    cout<< "Enter 0<x<10: " <<endl;
    do{
        cin>> x;
    }while(x <= 0 || x >= 10);

    cout<<endl;

    float floatI, array[10];

    for (i = 0; i < x; i++){
        floatI = i;
        array[i] = cos(floatI);
        cout<< array[i] <<endl;
    }
    cout<<endl;
    bubbleSort(array, x);

    for (i = 0; i < x; i++){
        cout<< array[i] <<endl;
    }

    return 0;
}

void bubbleSort(float arr[], int n){
    for(int i = 0; i < n; i++)
    {
          for(int j = 0; j < n-1; j++)
          {
               if(arr[j] < arr[j+1])
                    swap(&arr[j], &arr[j+1]);
          }
    }
}
    
void swap( float *a, float *b )
{
    float temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
