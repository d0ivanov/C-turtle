#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char number[14];
  char name[40];
  float profit[5];
} business;

int businessNum = 0; // broi firmi vyvedeni v programata

void addBusiness(business *);
void showBusiness(business *);
void showByAverage(business *);
void readFromFile(business *);
void allocateArray(business **, int);

int main()
{
  business *business_arr;
  char key;
  
  allocateArray(&business_arr, 0);
  
  printf("#######################################################\n");
  printf("# Press 1 to add a business.                          #\n");
  printf("# Press 2 to add array of business.                   #\n");
  printf("# Press 3 to see a business.                          #\n");
  printf("# Press 4 to see businesses with average profit over: #\n");
  printf("# Press 5 to read businesses from file.               #\n");
  printf("#                                                     #\n");
  printf("# Press 6 to exit.                                    #\n");
  printf("#######################################################\n");
 
  while(1)
  {
    printf("\nChoose option from the menu: ");
    key = getchar();
  
    switch(key)
    {
      case 49 : addBusiness(business_arr);
	break;
      case 50 : do
		{
		  addBusiness(business_arr);
		  printf("\nTo add new business press 1, to exit to menu press 2. \n");
		} while (getchar() == 49);
	break;
      case 51 : showBusiness(business_arr);
	break;
      case 52 : showByAverage(business_arr);
	break;
      case 53 : readFromFile(business_arr);
	break;
      case 54 : free(business_arr);
		return 0;
	break;
    }
  }
  
  
  return 0;
}

void addBusiness(business *business_arr)
{
  int i;
  
  if (businessNum/5 == 1) allocateArray(&business_arr, 1);
  
  printf("\nEnter business number: ");
  scanf("%s", business_arr[businessNum].number);
  
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
  char businessBul[14]; // bulstata na firmata
  int i, k;
  
  printf("\nEnter business BULSTAT number: ");
  scanf("%s", businessBul);
  
  for (i = 0; i < businessNum; i++)
  {
    if (strcmp(business_arr[i].number, businessBul) == 0)
    {
      printf("\nBusiness BULSTAT numer: %s\n", business_arr[i].number);
      printf("Business name: %s\n", business_arr[i].name);
      for (k = 1; k <= 5; k++)
      {
	printf("Profit for year %d: %.2f\n", k, business_arr[i].profit[k-1]);
      }
    }
  }
  
}

void showByAverage(business* business_arr)
{
  float averageProfit;
  int i, k;
  FILE *fp ;
  
  fp = fopen("kursova.txt", "w");
  
  printf("Average profit: ");
  scanf("%f", &averageProfit);
  
  for (i = 0; i < businessNum; i++)
  {
    if ((business_arr[i].profit[0] + business_arr[i].profit[1] + business_arr[i].profit[2] + business_arr[i].profit[3] + business_arr[i].profit[4])/5 > averageProfit)
    {
      printf("\nBusiness BULSTAT number: %s\n", business_arr[i].number);
      fprintf(fp, "\nBusiness BULSTAT number: %s\n", business_arr[i].number);
      printf("Business name: %s\n", business_arr[i].name);
      fprintf(fp, "Business name: %s\n", business_arr[i].name);
      for (k = 1; k <= 5; k++)
      {
	printf("Profit for year %d: %.2f\n", k, business_arr[i].profit[k-1]);
	fprintf(fp, "Profit for year %d: %.2f\n", k, business_arr[i].profit[k-1]);
      }
    }
  }
  
  fclose(fp);
  getchar();
}

void readFromFile(business *business_arr)
{
  FILE *fp;
  char key;
  
  fp = fopen("kursovaRead.txt", "r");
  if (fp != NULL)
  {
    key = fgetc(fp);
    rewind(fp);
    while (key != EOF)
    {
      key = fgetc(fp);
      printf("%c", key);
    }
  } else
  {
    printf("\nThere was error while trying to read the file.\n");
  }
  
  fclose(fp);
  getchar();
}

void allocateArray(business ** business_arr, int mode)
{
  business * temp;
  if (mode != 0 && mode != 1) return;
  
  if (mode == 0)
  {
    *business_arr = (business *)malloc(5 * sizeof(business));
  } else
  { 
    temp = *business_arr;
    *business_arr = (business *)malloc(((businessNum/5) + 5) * sizeof(business));
    *business_arr = temp;
  }
}