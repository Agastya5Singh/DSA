#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*top=NULL,*front=NULL,*rear=NULL;
void push_node(int x)
{
    struct node *t;
    t=(struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("\nStack Is Over Flowed ! :( ");
    }
    t->data=x;
    t->next=top;
    top=t;
}
int pop_node()
{
    int del_value=-1;
    struct node *t=top;
    if(top==NULL)
    {
        printf("\nStack Is Empty , NO Values To Delete :(");
    }
    else 
    {
        top=top->next;
        del_value = t->data;
        free (t);
    }
    return del_value;
}
void enqueue(int x)
{       
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if(front==NULL)
    {
        front=rear=t;
    }
    else
    {
        rear->next = t;
        rear=t;
    }
}

void display1(struct node *t)
{
    if(t==NULL)
    {
        printf("\nStack Is Empty");
    }
    printf("\n");
    while(t)
    {
        printf("%d ", t->data);
        t=t->next;
        printf("\n");
    }
}
int dequeue(void)
{
    int x=0;
    struct node *temp=front;
    x=front->data;
    front=front->next;
    temp->next=NULL;
    //free(temp); 
}
void reverse(struct node *p,struct node *s_t)
{
    if(front == rear)
    {
        printf("\n Queue is empty");
        return;
    }
    while(front)
    {
        push_node(front->data);
        front=front->next;
    }
    front=rear=NULL;
    while(top)
    {
       enqueue(pop_node());
    }
    rear->next=NULL;
}
void display(struct node *p)
{
    printf("\n");
    while(p)
    {
        printf("%d ", p->data);
        p=p->next;
    }
}

void main()
{
    struct node *s1=top;
    enqueue(7);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(0);
    enqueue(4);
    display(front);
    reverse(front,s1);
    display(front);
   
    //display(front);
}
