#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*tail=NULL;

void create(struct node **head, int n)
{
  struct node *ptr = *head;
  for (int i = 0; i < n; i++)
  {
    struct node *cur;
    cur = malloc(sizeof(struct node));
    printf("Enter the element %d: ", i + 1);
    scanf("%d", &cur->data);
    cur->next = cur->prev = NULL;
    if (*head == NULL)
    {
      *head = ptr = cur;
      (*head)->next = (*head)->prev = cur;
    }
    else
    {
      cur->prev = ptr;
      (*head)->prev = cur;
      cur->next = *head;
      ptr->next = cur;
      ptr = cur;
    }
  }
  tail = ptr;
}






void display(struct node *head)
{   
    struct node *ptr=head;
    if(head==NULL)
    {
        printf("the list is empty\n");
    }
    while(ptr->next)
    {
        if(ptr->next==head)
        {
            break;
        }
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("%d ",ptr->data);
    
}
int main()
{
     int n;
     printf("Enter the length of the list: ");
     scanf("%d",&n);
    create(&head,n);
    display(head);
    return 0;
}