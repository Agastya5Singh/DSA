#include <stdio.h>

void multi(int a[],int n){
  
  for (int i = 1; i <= n-2; i++)
  {
    a[i]=a[i-1]*a[i+1];
  }
  
  for (int i = 0; i < n; i++)
  {
    printf("%d ",a[i]);
  }
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
  multi(a,n);

  return 0;
}