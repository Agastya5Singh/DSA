#include<stdio.h>

void count(int a[], int n){
  int count0=0,count1=0;
  for (int i = 0; i < n; i++)
  {
    if(a[i]==0)
    {
      count0+=1;
    }
    if(a[i]==1)
    {
      count1+=1;
    }
  }
  printf("\nThe sorted array of 0 and 1 is:\n");
  for (int i = 0; i < count0; i++)
  {
    printf("%d ",0);
  }
  for (int i = 0; i < count1; i++)
  {
    printf("%d ",1);
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

  count(a,n);

  return 0;
}  