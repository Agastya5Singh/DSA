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



void delete(struct node**head,int del){
  struct node *ptr=*head,*qtr;
  int i=0;
  if (*head==NULL)
  {
    printf("The list is empty no deletion can take place :(");
  }
  if (del==0)
  {
    qtr=ptr->next;
    *head=qtr;
    free(ptr);
  }
  else
  {
    while ( ptr->next!=NULL && i<del-1 )
    {
      i++;
      ptr=ptr->next;
    }
    qtr=ptr->next;
    ptr->next=qtr->next;
    free(qtr);
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
  printf("List before deletion:");
  display(head);
  printf("\nList after deletion:");
  
  delete(&head,2);
  delete(&head,0);
  delete(&head,4);
  display(head);
  return 0;
}
