#include<stdio.h>

void mindis(int a[],int n){
  int l=0,u=0,lower,upper,count=0,min=100,m,p;
  printf("\nEnter the left limit:");
  scanf("%d",&lower);
  printf("Enter the right limit:");
  scanf("%d",&upper);

  for (int i = 0; i < n; i++)
  {
    int count=0;
    if (a[i]==lower)
    {
      l=i;
    }
    if (a[i]==upper)
    {
      u=i;
    }
    
    for (int i = l; i < u; i++)
    {
      count+=1;
    }
    if (count>0 && count<min)
    {
      min=count;
    }
  }
  
  printf("The number of elements between %d and %d are: %d",lower,upper,min);
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

  mindis(a,n);
  
  return 0;
}