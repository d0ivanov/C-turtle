#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void showArray();
void writeToArray();

char array[100];

int main()
{ 
 char key;
 
 
 printf("#####################################\n");
 printf("# Press 1 to add array to a file.   #\n");
 printf("# Press 2 to see array from a file. #\n");
 printf("#                                   #\n");
 printf("# Press 3 to exit.                  #\n");
 printf("#####################################\n");
 
 while(1)
 {
   printf("\nChoose option from the menu: ");
   key = getchar();
  
  switch(key)
  {
    case 49 : writeToArray();
      break;
    case 50 : showArray();
      break;
    case 51 : return 0;
      break;
  }
 }
 
 return 0;
}

void writeToArray()
{
  FILE *fp;
  int proceed = 1;
  char input[13];
  fp = fopen("arrayIsHere.txt", "w");
  if (fp != NULL)
  {
    while (proceed == 1)
    {
      scanf("%s", &input);
      fputc('n', fp);
      fprintf(fp, input);
      printf("Do you wish to proceed with adding values? (press '1' for yes, '2' for no)");
      do
      {
	scanf("%d", &proceed);
      }while (proceed != 1 && proceed != 2);
      getchar();
    }
  }
  else
  {
    printf("\nError reading file!\n");
  }
  fclose(fp);  
}

void showArray()
{
  char input;
  FILE *fp;
  
  fp = fopen("arrayIsHere.txt", "r");
  if (fp != NULL)
  {
    input = fgetc(fp);
    rewind(fp);
    printf("\nArray: \n");
    while (input != EOF)
    {
      input = fgetc(fp);
      if (input == 'n')
      {
	printf("\n");
      }
      else
      {
	printf("%c", input);
      }
    }
  }
  else
  {
    printf("\nError reading file!\n");
  }
  fclose(fp);
}

