#include<stdio.h>
int main() 
{
    int n,temp=0;
    printf("Enter the no. of element");
    scanf("%d",&n);
    int arr[n];
    printf("\n Enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    printf("Reversed Array is:");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    return 0;
}