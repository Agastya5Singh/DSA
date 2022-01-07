#include<stdio.h>
#include<stdlib.h>
int bin(int l,int h , int key,int a[])
{

    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key == a[mid])
        {
            return mid;
        }
        else if (key < a[mid])
        {
            return bin(l,mid-1,key,a);
        }
        else 
        return bin(mid+1,h,key,a);

    }
    return -1;
}
void main()
{
    int key = 1;

    int *a;
    int n=10;
    a=(int *)malloc(n *sizeof(int));
     for(int i = 0; i< n;i++)
     {
         int in;
         printf("\nPlease Enter A VAL : ");
   	     scanf("%d",&in); 
        a[i]=in;
     }
        printf("\nPlease Enter The  Key : ");
        scanf("%d",&key);
    for(int i=0; i<10; i++)
    {
        for(int j=i+1; j<10; j++)
        {
            if(a[i] > a[j])
            {
                int tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }
        }
    }
    for(int i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
    int m= bin(0,9,2,a);
    if(m != -1) 
    {
        printf("\nThe Key Is Present");
    }
    else
    printf("\nThe Key Is Not Present");
}