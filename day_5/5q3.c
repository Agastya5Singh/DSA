

#include <stdlib.h>
#include <stdio.h>

struct node
{
  struct node *pre;
  int data;
  struct node *next;
} *head = NULL, *tail = NULL;

void create(struct node **head, int n)
{
  struct node *ptr = *head;
  for (int i = 0; i < n; i++)
  {
    struct node *cur;
    cur = malloc(sizeof(struct node));
    cur->data = rand() % 100;
    cur->pre = NULL;
    cur->next = NULL;
    if (*head == NULL)
    {
      *head = ptr = cur;
    }
    else
    {
      cur->pre = ptr;
      ptr->next = cur;
      ptr = cur;
    }
  }
  tail = ptr;
}

void insert(struct node **head, int n, int a)
{
  struct node *cur;
  struct node *ptr = *head;
  cur = malloc(sizeof(struct node));
  cur->data = n;
  cur->pre = NULL;
  cur->next = NULL;
  if (*head == NULL)
  {
    *head = ptr = cur;
  }
  else if (a == 0)
  {
    cur->next = *head;
    cur->next->pre = cur;
    *head = cur;
  }
  else
  {
    int i = 0;
    while (ptr != NULL && i < a - 1)
    {
      i++;
      ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
      ptr->next = cur;
      cur->pre = ptr;
    }
    else if (ptr != NULL)
    {
      cur->pre = ptr;
      cur->next = ptr->next;
      ptr->next = cur;
      cur->next->pre = cur;
    }
  }
}

void delete (struct node **head, int del)
{
  struct node *ptr = *head;
  int i = 0;
  if (*head == NULL)
  {
    printf("The list is empty no deletion can take place :(");
  }
  if (del == 0)
  {
    *head = ptr->next;
    ptr->next->pre = NULL;
    free(ptr);
  }
  else
  {
    while (ptr != NULL && i <= del - 1)
    {
      i++;
      ptr = ptr->next;
    }
    if (ptr == NULL)
    {
      printf("\nindex %d can't be deleted as its not present.", del);
    }
    else if (ptr->next == NULL)
    {
      ptr->pre->next = NULL;
      free(ptr);
    }
    else
    {
      ptr->pre->next = ptr->next;
      ptr->next->pre = ptr->pre;
      free(ptr);
    }
  }
}

void checkempty(struct node **p)
{
  if (*p == NULL)
  {
    printf("\nThe List Is Empty :(");
  }
  else
  {
    printf("\nThe List Is not Empty :)");
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

void countnode(struct node **head)
{
  struct node *ptr = *head;
  int count = 0;
  for (ptr = *head; ptr != NULL; ptr = ptr->next)
  {
    count += 1;
  }
  printf("%d", count);
}

void revdis(struct node *p)
{
  if (p == NULL)
  {
    printf("\nThe List Is Empty :(");
  }
  printf("\n");
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->pre;
  }
}

void search(struct node **head, int sec)
{
  struct node *ptr = *head, *qtr;
  int i = 0;
  int count = 0;
  if (*head == NULL)
  {
    printf("The list is empty no deletion can take place :(");
  }
  if (sec == (*head)->data)
  {
    printf("The number is the first element of the Linked list present at %d node", count);
  }
  else
  {
    while (ptr->next)
    {
      count += 1;
      if (ptr->data != sec)
      {
        if (ptr->next->data == sec || ptr->next == NULL)
        {
          break;
        }
      }
      ptr = ptr->next;
    }
    printf("The number is present at %d node and is the %d element of the Linked list", count,count+1);
  }
}

int main()
{
  int n, d, p, del, a, da;
  printf("Enter the length of the list: ");
  scanf("%d", &n);
  create(&head, n);

  printf("Original Linked list:");
  display(head);

  do
  {
    int ch;
    int n, d, p, del, a;
    printf("\n\nSelect option: ");
    printf("\n1. Traverse the list forword");
    printf("\n2. Traverse the list backward");
    printf("\n3. Check if the list is empty");
    printf("\n4. Insert a node at the certain position");
    printf("\n5. Delete a node at the certain position");
    printf("\n6. Count the total number of nodes");
    printf("\n7. Search for an element in the linked list");
    printf("\n8. Exit.");

    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("\nThe Linked list:");
      display(head);
      break;  
    case 2:
      printf("\nReversed Linked list:");
      revdis(tail);
      break;
    case 3:
      printf("\nChecking wheather the list is empty or not:");
      checkempty(&head);
      break;
    case 4:
      printf("\nEnter the data of the list to be inserted: ");
      scanf("%d", &d);
      printf("Enter the postion of the list to be inserted: ");
      scanf("%d", &p);
      printf("List after insertion:");
      insert(&head, d, p);
      display(head);
      break;
    case 5:
      printf("\nEnter the index of the list to be deleted: ");
      scanf("%d", &del);
      printf("List after deletion:");
      delete (&head, del);
      display(head);
      break;
    case 6:
      printf("\nTotal number of nodes in the Linked list: ");
      countnode(&head);
      break;
    case 7:
      printf("\nEnter the data whose position is to be found: ");
      scanf("%d", &a);
      search(&head, a);
      break;
    case 8:
      return 0;
    default:
      printf("\nInvalid choice entered. Try again\n");
    }
  } while (1);

}