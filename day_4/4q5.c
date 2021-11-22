#include<stdio.h> 
#include<stdlib.h>

struct node 
{
    int data;
    struct node  *next;
}*head=NULL,*last=NULL;
int count();
void create(int key)
{ 
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=key;
    t->next=NULL;
    if(head==NULL) 
    head=last=t;
    else
    {
        t->next=last;
        last=t;
    }
}
void display(struct node *p)
{ 
    printf("\n");
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void release(void)
{
    struct node *temp1=head,*temp2;
    while(temp1)
    {
        temp2=temp1->next;
        free(temp1);
        temp1=temp2;
    }

}
void main()
{
    create(2);
    create(0);
    create(2);
    create(9);
    create(1);
    create(4);
    create(2);
    display(last);
    release();
}