#include<stdio.h>
#include<stdlib.h>

void main()
{ int size=4;
    int key =1;
    int a[size];
    int q=0;
    a[q]=2;
    a[++q]=3;
    a[++q]=3;
    a[++q]=4;
    int count=0;
    for(int i=0; i<size-1; i++)
    {
        for(int j=0;j<size-1;j++)
        {
          if(a[i] == a[j])
          {
              count++;
              if(count >= size/2)
              {
                printf("The Number Is %d ",a[i]); 
                break;    
                }
          }
        }

    }   

}