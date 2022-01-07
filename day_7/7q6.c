#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
} *rear,*front,*temp,*newNode;

void create()
{
  front = rear = NULL;
}

void enqueue(int data)
{
 newNode = (struct node*) malloc(sizeof(struct node));
 newNode -> data = data;
 newNode -> next = NULL;
 if(front == NULL)
 front = rear = newNode;
 else
 { 
   rear -> next = newNode;
   rear = newNode;
 }
  rear -> next = front; 
}

int dequeue()
{
 int x;
 if (front == NULL)
 {
 return -1; 
 }
 else if (front == rear)
 {
  x = front->data;
  free(front);
  front = rear = NULL;
 }
 else
 {
 struct node *temp = front;
 x = temp -> data;
 front = front -> next;

 rear -> next = front;
 free(temp);
 }
return x;
}

int empty()
{
  if(front == NULL)
  {
    return 1;
  }
  else
  return 0;
}

void display()
{
  struct node *temp = front;
  printf("\nCIRCULAR QUEUE : ");
  do
  {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  while (temp != front);
}

int main()
{
  int num,choice;
  while(1)
 {
   printf("\n\nQUEUE OPERATIONS\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n\n");
   scanf("%d",&choice);
  switch (choice)
  {
     case 1:
       printf("\nEnter item : ");
       scanf("%d",&num);
       enqueue(num);
     break;
     case 2:
        if(!(empty()))
        printf("\nDequeued element : %d",dequeue());
        else
        printf("\nEMPTY QUEUE\n");
        break;
     case 3:
        display();
      int t;
      printf("Please Enter 0 To Go To The Main Menu : ");
      scanf("%d",&t);
      break;
      default: exit(0); 
  }
}
 return 0;
}