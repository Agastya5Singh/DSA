#include <stdlib.h>
#include <stdio.h>

struct node
{
  int data;
  struct node *next;
} *head = NULL, *tail = NULL;




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


void insert(struct node **head, int n, int a)
{
  struct node *cur;
  struct node *ptr = *head;
  cur = malloc(sizeof(struct node));
  cur->data = n;
  cur->next = NULL;
  if (*head == NULL || a == 0)
  {
    cur->next = *head;
    *head = cur;
  }
  else
  {
    int i = 1;
    while (ptr != NULL && i < a)
    {
      i++;
      ptr = ptr->next;
    }
    if (ptr != NULL)
    {
      cur->next = ptr->next;
      ptr->next = cur;
    }
  }
}

void delete (struct node **head, int del)
{
  struct node *ptr = *head, *qtr;
  int i = 0;
  if (*head == NULL)
  {
    printf("The list is empty no deletion can take place :(");
  }
  if (del == (*head)->data)
  {
    qtr = ptr->next;
    *head = qtr;
    free(ptr);
  }
  else
  {
    while (ptr->next)
    {
      if (ptr->data != del)
      {
        if (ptr->next->data == del || ptr->next==NULL)
        {
          break;
        }
      }
      ptr = ptr->next;
    }
    qtr = ptr->next;
    ptr->next = qtr->next;
    free(qtr);
  }
}

void display(struct node *p)
{
  if (p == NULL)
  {
    printf("\nThe List Is Empty :(");
  }
  printf("\n");
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
}

int main()
{
  int n, d, i;
  printf("Enter the length of the list: ");
  scanf("%d", &n);
  create(&head, n);
  printf("List before insertion:");
  display(head);
  printf("\nEnter the data to be deleted: ");
  scanf("%d", &d);
  printf("List after deletion:");
  delete (&head, d);
  display(head);
  printf("\nList after insertion:");
  insert(&head, d, 0);
  display(head);
  return 0;
}
