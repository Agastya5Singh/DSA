#include<stdio.h>
#include<stdlib.h>

struct node{
struct node *prv;
int data;
struct node *next;
} *head=NULL,*tail=NULL;

void create(struct node **head,int n)
{
   for(int i=0;i<n;i++)
    {
    struct node *cur=NULL;
    
        cur=malloc(sizeof(struct node));
        printf("Enter the elements: ");
        scanf("%d",&cur->data);
        cur->prv=cur->next=NULL;
    
    if(*head==NULL)
    {
        *head=tail=cur;
    }
    else{
        cur->prv=tail;
        tail->next=cur;
        tail=cur;
    }
    }
}

void insert(struct node **h,int val,int pos)
{
    struct node *cur;
    struct node *ptr;
    cur=malloc(sizeof(struct node));
    cur->data=val;
    cur->next=cur->prv=NULL;
    if(*h==NULL)
    {
        *h=cur;
    }
    else if(pos==0)
    {
        cur->next=*h;
        cur->next->prv=cur;
        *h=cur; 
    }
    else{
    ptr=*h;
    int i=0;
    while(i<pos-1 && ptr != NULL)
    {
        i++;
        ptr=ptr->next;
    }
    if (ptr->next==NULL)
    {
        cur->prv=ptr;
        ptr->next=cur;
    }
    else
    {
        cur->prv=ptr;
        cur->next=ptr->next;
        ptr->next=cur;
        cur->next->prv=cur;
    }
    }
}


 
 
void display(struct node *head)
{   
    if(head==NULL)
    {
        printf("the list is empty\n");
    }
    
    
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}
int main()
{   int n;
     printf("Enter the length of the list: ");
  scanf("%d",&n);
  create(&head,n);
    display(head);
}
