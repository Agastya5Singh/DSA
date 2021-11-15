#include <stdio.h>

int main()
{
  printf("\n Enter the size of array: ");
  int size;
  scanf("%d",&size);
  int a[size];
  printf("\n Enter the Elements:");
  for(int i=0;i<size;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("\n Enter the right limit:");
  int right;
  scanf("%d",right);
  printf("\n Enter the left limit:");
  int left;
  scanf("%d",left);
  for(int i=0;i<size;i++)
  {
    if(a[i]==right)
    {
      right=i;
    }
  }
  for(int i=0;i<size;i++)
  {
    if(a[i]==left)
    {
      left=i;
    }
  }
  int count =0;
  for(left;left<=right;left++)
  {
    printf("%d",a[left]);
    count++;
  }
  printf("\n The no. of element printed is : %d",count);
  return 0;
}