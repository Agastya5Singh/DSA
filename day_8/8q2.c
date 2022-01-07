#include <stdio.h>

#include <stdlib.h>

int main()
{
  int n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  int array[n],key,i,j,low,high,position,choice;

    void binary_search(int key,int array[100],int n);


    printf("Enter the element of array: \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&array[i]);
    }

    printf("Enter the element to be searched:");

    scanf("%d",&key);

    binary_search(key,array,n);

return 0;
}

void binary_search(int key,int array[100],int n)
{

    int mid,i,low,high;

    low = 1;

    high = n;

    mid = (low + high)/2;

    i=1;

    while(key != array[mid])
    {

        if(key <= array[mid])
        {

            low = 1;

            high = mid+1;

            mid = (low+high)/2;

        }
        else
        {

            low = mid+1;

            high = n;

            mid = (low+high)/2;

        }

}
    printf("Key %d found at position %d",key,mid);
}