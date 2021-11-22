#include<stdio.h> 
#include<stdlib.h>

struct node 
{
    int data;
    struct node  *next;
}*head=NULL,*last=NULL;
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
        last->next=t;
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
    create(2);
    create(0);
    create(2);
    create(9);
    create(1);
    create(4);
    create(2);
    invert(head,4);
    display(head);
    release();
}

// output:-
// 1 4 2 2 0 2 9