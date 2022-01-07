#include <stdio.h>

int main()
{
  int transpose[5][4];
  int sparseMatrix[4][5] =
      {
          {0, 0, 3, 0, 4},
          {0, 0, 5, 7, 0},
          {0, 0, 0, 0, 0},
          {0, 2, 6, 0, 0}};

  int size = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++)
      if (sparseMatrix[i][j] != 0)
        size++;

  int tupleMatrix1[3][size];

  int k = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++)
      if (sparseMatrix[i][j] != 0)
      {
        tupleMatrix1[0][k] = i;
        tupleMatrix1[1][k] = j;
        tupleMatrix1[2][k] = sparseMatrix[i][j];
        k++;
      }
  printf("\nThe matrix using 3 tuple method:\n");
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < 3; j++)
      printf("%d ", tupleMatrix1[j][i]);

    printf("\n");
  }
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4; j++)
    {
      transpose[i][j] = sparseMatrix[j][i];
    }

  printf("\nThe tranpose matrix:\n");
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      printf("%d ", transpose[i][j]);
    }
    printf("\n");
  }

  int size2 = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++)
      if (transpose[i][j] != 0)
        size2++;

  int tupleMatrix2[3][size2];

  int k1 = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++)
      if (transpose[i][j] != 0)
      {
        tupleMatrix2[0][k1] = i;
        tupleMatrix2[1][k1] = j;
        tupleMatrix2[2][k1] = transpose[i][j];
        k1++;
      }
  printf("\nThe transposed matrix using 3 tuple method:\n");
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < size; j++)
      printf("%d ", tupleMatrix2[i][j]);

    printf("\n");
  }

  return 0;
}