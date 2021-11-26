#include <stdio.h>
#include <stdlib.h>
  

struct node {
  int data;
  struct node *next;
} *head;
 
void initialize(){
    head = NULL;
}
 

void insert(int num) {
    
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data  = num;
   
    newNode->next = head;
 
    head = newNode;
    printf("Inserted Element : %d\n", num);
}
 
void printMiddleNode(struct node *head){

    if(head == NULL){
        printf("Error : Invalid Input !!!!\n");
        return INT_MIN;
    }
    struct node *slow, *fast;
    slow = fast = head;
   
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
     
    printf("\nMiddle Node : %d\n", slow->data);
}
 

void printLinkedList(struct node *nodePtr) {
  while (nodePtr != NULL) {
     printf("%d", nodePtr->data);
     nodePtr = nodePtr->next;
     if(nodePtr != NULL)
         printf("-->");
  }
}
  
int main() {
    initialize();
   
    insert(2);  
    insert(0); 
    insert(2); 
    insert(9);
    insert(1);
    insert(4);
    insert(2);

    printf("\nLinked List\n");
    printLinkedList(head);
     
   
    printMiddleNode(head);
    return 0;
}