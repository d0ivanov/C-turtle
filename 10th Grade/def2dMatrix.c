#include <stdio.h>
#include <stdlib.h>

#define NUMX 10
#define NUMY 20

void defMatrix(int x, int y, int ***);

int main()
{
  int **test;
  int i, k;
  
  defMatrix(NUMX, NUMY, &test);
  
  printf("\n");
  
  for (i = 0; i < NUMX; i++)
  {
    for (k = 0; k < NUMY; k++)
    {
      printf("%d", test[i][k]);
    }
    printf("\n");
  }
  
  return 0;
}

void defMatrix(int x, int y, int ***matrix)
{
  int row, column, i;
  int ** temp = (int **)malloc(sizeof(int *) * x);
  for (i = 0; i < x; i++)
  {
    temp[i]= (int *) malloc(y * sizeof(int));
  }
  *matrix = temp;
  
  for (row = 0; row < x; row++)
  {
    for (column = 0; column < y; column++)
    {
      (*matrix)[row][column] = 0;
    }
  }
}