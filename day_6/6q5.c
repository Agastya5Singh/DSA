#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node *next;
}*top=NULL;

void push(char x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    t->next=top;
    top=t;
}
void pop()
{

    struct node *t=top;
    top=top->next;
    free(t);
}
void display(struct node *t)
{
    if(t==NULL)
    {
        printf("\nStack Is Empty :(");
    }
    else
    while(t)
    {
        printf("%c ", t->data);
        printf("\n");
        t=t->next;
    }
}
int isBalanced(char *exp)
{
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(top==NULL)
            return 0;
                 pop();

        }
    }
    if(top==NULL)
        {
            return 1;
        }
        else 
        return 0;
 }
void main()
{
    char *exp="{(([(a+b)*(c-d)]))}";
    //printf("%d ",isBalanced(exp));
    if(isBalanced(exp) == 1)
    {
        printf("\nYes");

    }
    else
    printf("\nNo");
    
}


