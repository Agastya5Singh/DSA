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
void delete(struct node *p)
{
    struct node *prev=head;
    for(int i =0;prev->next!=p;i++)
        prev=prev->next;
        prev->next=p->next;
}
void rem_dup(struct node *p)
{
    struct node *q;
     if(p->data == head->data)
    {
        struct node *temp=head;
        head=head->next;
        free(temp);
        p=head;
        p=p->next;
    }
    while(p)
    {   
        q=p->next;
        while(q)
        {
            if(p->data == q->data )
            {
                delete(q);
            }
            q=q->next;
        }
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
    rem_dup(head);
    display(head);
    release();
}

// output:-
// 0 2 9 1 4 

