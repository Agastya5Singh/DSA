#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
struct node 
{
    char text;
    struct node  *next;
}*head=NULL,*last=NULL,*head2=NULL,*last2=NULL;
void create(char name[100])
{ 
    for(int i=0;name[i]!='\0';i++)
    {
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->text=name[i];
    t->next=NULL;
    if(head==NULL) 
    head=last=t;
    else
    {
        last->next=t;
        last=t;
    }
    }
}
void display(struct node *p)
{ 
    printf("\n");
    while(p)
    {
        printf("%c",p->text);
        p=p->next;
    }
}
void compare(struct node *p)
{ 
    while(p)
    {
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->text=p->text;
    t->next=NULL;
    if(head2==NULL) 
    head2=last2=t;
    else
    {
        t->next=last2;
        last2=t;
    }
    p=p->next;
    }

}
void pall(struct node *p,struct node *q)
{
    while(p && q)
    {
        if(p->text != q->text)
        {
            printf("\nIt Is Not  A Palindrom");
            return;
        }
        p=p->next;
        q=q->next;
    }
    printf("\nIt Is A Palindrom");

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
void main ()
{
    char a[100];
    printf("\nPlease Enter The String : ");
    scanf("%s",a);
    create(a);
    compare(head);
    pall(head,last2);
    release();
}