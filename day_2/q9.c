/*WAP to find out the kth smallest and kth largest element stored in a dynamic
array of n integers, where k<n.*/

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
}

int main()
{
  int n, i, k;

  printf("Enter the size of array:-");
  scanf("%d", &n);
  int a[n];

  for (i = 0; i < n; i++)
  {
    printf("Enter element %d : ", i + 1);
    scanf("%d", &a[i]);
  }

  printf("Enter the value of k: ");
  scanf("%d", &k);

  sort(a,n);
  printf("The sorted array:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }

  printf("\nThe kth smallest element: %d",a[k-1]);
  printf("\nThe kth largest element: %d",a[n-k]);

  return 0;
}  