#include <stdio.h>
#include <stdlib.h>

int **defMatrix(int x, int y);

int main()
{
  int **test = defMatrix(10, 10);
  int i, k;
  
  printf("\n");
  for (i = 0; i < 10; i++)
  {
    for (k = 0; k < 10; k++)
    {
      printf("%d", test[i][k]);
    }
    printf("\n");
  }
  return 0;
}

int **defMatrix(int x, int y)
{
  int row, column;
  int i;
  int ** matrix = (int **) malloc (x * sizeof(int *));
  int * matrixReturn;
  
  for (i = 0; i < x; i++)
  {
    matrix[i]= (double *) malloc(y * sizeof(int));
  }
  
  for (row = 0; row < y; row++)
  {
    for (column = 0; column < x; column++)
    {
      if (row == 0 || row == y-1 || column == 0 || column == x-1) 
      {
	matrix[row][column] = 1;
      } else 
      {
	matrix[row][column] = 0;
      }
    }
  }
  
  matrixReturn = matrix;
  
  return matrixReturn;
}

