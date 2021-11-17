#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL, *tail=NULL;

int main() 
  {
    int i;
    struct node *cur;
    for(i=0;i<4;i++)
    {
        cur=malloc(sizeof(struct node));
        scanf("%d",&cur->data);
        cur->next=NULL;
        if(head==NULL)
        {
            head=tail=cur;
        }
        else
        {
            tail->next=cur;
            tail=cur;
        }
        if(head==NULL)
        {
            printf("list is empty\n");
        }

    }
    cur=head;
    while(cur!=NULL)
    {
        printf("%d\n",cur->data);
        cur=cur->next;
    }
}


// OUTPUT
// 4
// 2
// 6
// 7
// 4
// 2
// 6
// 7