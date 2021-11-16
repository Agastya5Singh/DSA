#include <stdio.h>

void largest(int a[], int n)
{
  int i, l = 0;
  for (i = 1; i < n; i++)
  {
    if (a[l] < a[i])
    {
      l = i;
    }
  }
  printf("The largest number is: %d", a[l]);
}

int main()
{
  int n;
  printf("Enter the number of elements in the array:-");
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++)
  {
    printf("Enter element %d:- ", i + 1);
    scanf("%d", &a[i]);
  }

  printf("The array is:-\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  
  printf("\n");
  largest(a, n);

  return 0;
}