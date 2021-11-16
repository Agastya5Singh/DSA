#include <stdio.h>

void sort(int aa[], int n)
{
  int i, j, min, b;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (aa[min] > aa[j])
      {
        min = j;
      }
    }
    b = aa[i];
    aa[i] = aa[min];
    aa[min] = b;
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d ", aa[i]);
  }
}

int main()
{
  int n, i, u, l, lower, upper, count = 0;

  printf("Enter the size of array:-");
  scanf("%d", &n);
  int a[n];

  for (i = 0; i < n; i++)
  {
    printf("Enter element %d : ", i + 1);
    scanf("%d", &a[i]);
  }

  printf("Enter the lower limit:-");
  scanf("%d", &lower);
  printf("Enter the upper limit:-");
  scanf("%d", &upper);

  for (i = 0; i < n; i++)
  {
    if (a[i] == lower)
    {
      l = i;
      break;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (a[i] == upper)
    {
      u = i;
    }
  }
  
  printf("\nThe sorted array: \n");
  sort(a,n);

  printf("\nThe numbers between %d and %d are:-\n", lower, upper);
  for (i = l; i <= u; i++)
  {
      count += 1;
      printf("%d ", a[i]);
  }

  printf("\nThe number of elements found between %d and %d are:- %d", lower, upper, count);

  return 0;
}