#include<stdlib.h>
#include<stdio.h>

struct node{
  int data;
  struct node *next;
}*head=NULL,*tail=NULL;

void create(int n){

  struct node *cur;
  cur=malloc(sizeof(struct node));
  cur->data=n;
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

void insert(struct node *p){
  
}

int main()
{
  create(5);
  create(7);
  create(4);
  create(10);
  create(9);
  create(0);
  display(head);
  return 0;
}