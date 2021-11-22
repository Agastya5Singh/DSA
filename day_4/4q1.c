#include<stdlib.h>
#include<stdio.h>

struct node{
  int data;
  struct node *next;
}*head=NULL,*tail=NULL;

void create(struct node**head,int n){

  for (int i = 0; i < n; i++)
  {
  struct node *cur;
  cur=malloc(sizeof(struct node));
  printf("Enter the elements: ");
  scanf("%d",&cur->data);
  cur->next=NULL;
  if(*head==NULL)
  {
    *head=tail=cur;
  }
  else
  {
    tail->next=cur;
    tail=cur;
  } 
  }
}  

void insert(struct node**head,int n,int a){
  struct node *cur;
  struct node *ptr =*head;
  cur=malloc(sizeof(struct node));
  cur->data=n;
  cur->next=NULL;
  if(*head==NULL || a==0){
    cur->next=*head;
    *head=cur;
  }
  else 
  {
    int i=0;
    while ( ptr->next!=NULL && i<a-1 )
    {
      i++;
      ptr=ptr->next;
    }
    cur->next=ptr->next;
    ptr->next=cur;
  }
}



void display(struct node *p){
  if(p==NULL) 
  {
    printf("\nThe List Is Empty :(");
  }
  printf("\n");
  while(p!=NULL)
  {
    printf("%d ",p->data);
    p=p->next;
  }
}

int main()
{
  int n;
  printf("Enter the length of the list: ");
  scanf("%d",&n);
  create(&head,n);
  printf("List before insertion:");
  display(head);
  printf("\nList after insertion:");
  insert(&head,34,3);
  insert(&head,4,0);
  insert(&head,4,5);
  display(head);
 
  return 0;
}
