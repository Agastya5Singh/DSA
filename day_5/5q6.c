#include <stdio.h>
#include <stdlib.h>
 #include <limits.h> 

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
 
void convertToCircularLL(struct node *head){
   
    if(head == NULL){
        printf("Error : Invalid Input !!!!\n");
        return INT_MIN;
    }
    struct node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
     
    temp->next = head;
}
 

void printCircularLinkedList(struct node *head) {
    struct node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
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
    
    convertToCircularLL(head);
     
   
    printCircularLinkedList(head);
    return 0;
}