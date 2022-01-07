#include<stdio.h>
#include<stdlib.h>

void main()
{
    int key = 1;

    int *p;
    int n=5;
    p=(int *)malloc(n *sizeof(int));
     for(int i = 0; i< n;i++)
     {
         int in;
         printf("\nPlease enter the value : ");
   	     scanf("%d",&in); 
        p[i]=in;
     }
        printf("\nPlease enter the  key : ");
        scanf("%d",&key);
    for(int i=0; i<10; i++)
    {
        if (key == p[i])
        {
            printf("\nThe Key Is Present In The Array");
            break;
        }
    }    
}