#include <stdio.h>

void main()
{
  int mat[5][5];
  int i, j;
  int m, n;
  int no_zero = 0;

  printf("Enter the order\n");
  scanf("%d %d", &m, &n);
  printf("Enter the elements\n");
  for (i = 0; i < m; ++i)
  {
    for (j = 0; j < n; ++j)
    {
      scanf("%d", &mat[i][j]);
      if (mat[i][j] == 0)
      {
        ++no_zero;
      }
    }
  }
  if (no_zero > ((m * n) / 2))
  {
    printf("The given Matrix is Sparse Matrix !!! \n");
  }
  else
    printf("The given Matrix is not a Sparse Matrix \n");
  
}