#include <stdio.h>
#include <stdlib.h>

#define NUMX 10
#define NUMY 10

void defMatrix(int x, int y, int ***);

int main()
{
  int **test;
  int i, k;
  
  defMatrix(NUMX, NUMY, &test);
  //printf("debugfucku");
  printf("\n");
  //printf("debug6");
  /*for (i = 0; i < NUMX; i++)
  {
    //printf("debug5");
    for (k = 0; k < NUMY; k++)
    {
      //printf("debug4");
      printf("%d", test[i][k]);
    }
    printf("\n");
  }
  */
  printf("\n%d\n", test[0][0]);
  return 0;
}

void defMatrix(int x, int y, int ***matrix)
{
  int row, column, i;
  
  matrix = (int **) malloc (x * sizeof(int *));
  for (i = 0; i < x; i++)
  {
    matrix[i]= (int *) malloc(y * sizeof(int));
  }
  //printf("debug2");
  printf("%d", sizeof(matrix)); // 4 ???
  
  for (row = 0; row < y; row++)
  {
    for (column = 0; column < x; column++)
    {
      if (row == 0 || row == y - 1 || column == 0 || column == x - 1) 
      {
	matrix[row][column] = 1;
      } else 
      {
	matrix[row][column] = 0;
      }
    }
  }
  
  //printf("\n%d\n", matrix[0][0]);
  //printf("debug3");
}

/*int **defMatrix(int x, int y)
{
  int row, column;
  int i;
  int ** matrix = (int **) malloc (x * sizeof(int *));
  int * matrixReturn;
  
  for (i = 0; i < x; i++)
  {
    matrix[i]= (int *) malloc(y * sizeof(int));
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
}*/