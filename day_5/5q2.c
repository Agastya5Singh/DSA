#include <stdio.h>  
    #include <stdlib.h>

  
struct node{  
    int data;  
    struct node *previous;  
    struct node *next;  
};      
   

struct node *head=NULL, *tail = NULL;  
   
  
void addNode(int data) {  
    
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
      
    
    if(head == NULL) {  
       
        head = tail = newNode;  
        
        head->previous = NULL;  
        
        tail->next = NULL;  
    }  
    else {  
        
        tail->next = newNode;  
         
        newNode->previous = tail;  
         
        tail = newNode;  
      
        tail->next = NULL;  
    }  
}  
   
  
void reverse() {  
   
    struct node *current = head, *temp = NULL;  
      
     
    while(current != NULL) {  
        temp = current->next;  
        current->next = current->previous;  
        current->previous = temp;  
        current = current->previous;  
    }  
   
    temp = head;  
    head = tail;  
    tail = temp;  
}  
   
 
void display() {  
   
    struct node *current = head;  
    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    while(current != NULL) {  
        
        printf("%d ", current->data);  
        current = current->next;  
    }  
}  
   
int main()  
{  
    
    addNode(2);  
    addNode(0);  
    addNode(2);  
    addNode(9);  
    addNode(1);  
    addNode(4);  
    addNode(2);
    printf("Original List: \n");  
    display();  
      
   
    reverse();  
      
     
    printf("\nReversed List: \n");  
    display();  
   
    return 0;  
}