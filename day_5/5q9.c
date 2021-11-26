#include<stdio.h> 
#include<stdlib.h>

struct node 
{
    int data;
    struct node  *next;
}*head=NULL,*last=NULL;
void create(int key)
{ 
    struct node *T;
    T=(struct node *)malloc(sizeof(struct node));
    T->data=key;
    T->next=NULL;
    if(head==NULL) 
    head=last=T;
    else
    {
        last->next=T;
        last=T;
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
void invert(struct node *p,int k)
{
    struct node *temp1=head;
    struct node *temp3=head;
    for(int i=1;i<k;i++)
    {
        temp3=temp3->next;
    }
    p=temp3->next;
    temp3->next=NULL;
    head=p;
    struct node *temp2=head;
    while(temp2->next)
    {
        temp2=temp2->next;
    }
    temp2->next=temp1;
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
    create(10);
    create(20);
    create(30);
    create(40);
    create(50);
    create(60);
  
    invert(head,4);
    display(head);
    release();
}