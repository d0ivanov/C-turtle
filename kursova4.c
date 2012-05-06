#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char businessNumber[13];
  char name[40];
  float profit[5];
} business;

int businessNum = 0; // broi firmi vyvedeni v programata

void addBusiness(business *);
void showBusiness(business *);

int main()
{
  business business_arr[20];
  //business *businessPointer = business_arr;
  char key;
 
 
  printf("###############################\n");
  printf("# Press 1 to add a business.  #\n");
  printf("# Press 2 to see a business.  #\n");
  printf("#                             #\n");
  printf("# Press 3 to exit.            #\n");
  printf("###############################\n");
 
  while(1)
  {
    printf("\nChoose option from the menu: ");
    key = getchar();
  
    switch(key)
    {
      case 49 : addBusiness(business_arr);
	break;
      case 50 : showBusiness(business_arr);
	break;
      case 51 : return 0;
	break;
    }
  }
  
  
  return 0;
}

void addBusiness(business *business_arr)
{
  int i;
  
  printf("\nEnter business number: ");
  scanf("%s", business_arr[businessNum].businessNumber);
  
  //getchar();
  
  printf("\nEnter business name: ");
  scanf("%s", business_arr[businessNum].name);
  
  for (i = 1; i <= 5; i++)
  {
    printf("\nEnter business profit for year %d: ", i);
    scanf("%f", &business_arr[businessNum].profit[i-1]);
    getchar();
  }
  
  businessNum++;
}

void showBusiness(business *business_arr)
{
  char businessBul[13]; // bulstata na firmata
  int i, k;
  
  printf("\nEnter business BULSTAT number: ");
  scanf("%s", businessBul);
  
  printf("\n%s, %s", businessBul, business_arr[0].businessNumber);
  
  for (i = 0; i < businessNum; i++)
  {
    if (business_arr[i].businessNumber == businessBul)
    {
      printf("Business BULSTAT numer: %s\n", business_arr[i].businessNumber);
      printf("Business name: %s\n", business_arr[i].name);
      for (k = 1; k <= 5; k++)
      {
	printf("Profit for year %d: %f\n", k, business_arr[i].profit[k-1]);
      }
    }
  }
  
}

