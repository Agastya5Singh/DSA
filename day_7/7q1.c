#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/*Q1. WAP to implement a stack which will support three additional operations in
addition to push and pop:
a) peekLowestElement - return the lowest element in the stack without
removing it from the stack
b) peekHighestElement - return the highest element in the stack without
removing it from the stack
c) peekMiddleElement - return the (size/2+1) th lowest element in the stack
without removing it from the stack.
*/ 
#define MAX 15

typedef struct
{
    int data[MAX];
    int top;
}stack;

void push(stack *s, int value);
void pop(stack *s, int *temp);
void display(stack *s);
int isEmpty(stack *s);
void peek(stack *s);
int input();
void peekLowestElement(stack *s);
void peekHighestElement(stack *s);
void peekMiddleElement(stack *s);

void init(stack *s)
{
    s-> top= -1; //initially we take top to be -1
}

int main(void)
{
    int cont= 1, value, b;
    stack s1;
    init(&s1);
    do{
        printf("\n1.PUSH\n2.POP\n3.CHECK IF EMPTY\n4.PEEK\n5.DISPLAY STACK:\n");
        int choice= input();
        switch (choice)
            {
            case 1: 
            {
                printf("\nEnter element in stack: ");
                scanf("%d", &value);
                push(&s1, value);
                break;
            }

            case 2:
            {
                printf("\nPopping an item: ");
                pop(&s1, &b);
                break;
            }

            case 3:
            {
                printf("\nChecking if the stack is empty: ");
                int resp= isEmpty(&s1);
                if (resp!=1)
                {
                printf("NOT EMPTY\n");
                }
                break;
            }
            case 4:
            {
                printf("\nSelect peek option:n\n1.peekLowestElement\n2. peekHighestElement\n3. peekMiddleElement: ");
                int select= input();
                switch (select)
                {
                    case 1:
                    {
                        peekLowestElement(&s1);
                        break;
                    }
                    case 2:
                    {
                        peekHighestElement(&s1);
                        break;
                    }
                    default:
                    {
                        peekMiddleElement(&s1);
                        break;
                    }
                }
                break;
            }
            default:
            {
                printf("\nStack entered: top-> ");
                display(&s1);
                break;
            }
        }
        printf("\nDo you wish to continue?\n1.YES\n2.No: ");
        int r; scanf("%d", &r);
        if (r!=1)
        {
            cont++;
        }
    }
    while(cont==1);

    printf("\nDo you wish to go again?\n1.YES\n2.No: ");
    int r; scanf("%d", &r);
    if (r!=1)
    {
        cont==1;
    }
    system("cls");

}

void push(stack *s, int val)
{
    if (s-> top== MAX-1)
    {
        printf("\nOVERFLOW. STACK IS ALREADY FULL.");
        return;
    }
    else
    {
        s-> top++;
        s-> data[s-> top]= val;
        return;
    }    
}

void pop(stack *s, int *temp)
{
    if (s-> top== -1)
    {
        printf("\nUNDERFLOW");
        return;
    }
    else
    {
        *temp= s->data[s->top];
        printf("\nPopped item: %d\n", *temp);
        s-> top--;
        return;
    }
}

int isEmpty(stack *s)
{
    if (s-> top== -1)
    {
        printf("\nStack is empty");
        return 1;
    }
    else
    {
        return 0;
    }
}

void display(stack *s)
{
    if (s-> top== -1)
    {
        printf("\nStack is empty");
        return;
    }
    else
    {
        int i;
        for (i=s->top; i >=0; i--)
        {
            printf("\t%d\t", s-> data[i]);
        }
    }
}
int input()
{
    int num; scanf("%d", &num);
    return num;
} 
void peek(stack *s)
{
    if (s-> top== -1)
    {
        printf("\nStack is empty");
        return;
    }
    else
    {
        printf("\ntop-> %d", s->data[s->top]);
    }
}

void peekLowestElement(stack *s)
{
    int min;
    if (s-> top== -1)
    {
        printf("\nStack is empty");
        return;
    }

    else
    {
        min= s-> data[s-> top];
        int i;
        for (i= s->top; i >=0; i--)
        {
            if (s-> data[i] < min)
            {
                min= s-> data[i];
            }
        }

        printf("\nLowest element of stack: %d", min);
    }
}

void peekMiddleElement(stack *s)
{
    if (s-> top== -1)
    {
        printf("\nStack is empty");
        return;
    }

    else
    {
        int size= s-> top+ 1, pos= ((size/2)), value, i;
        for (i= s->top; i >=0; i--)
        {
            if (i== pos)
            {
                value= s-> data[i]; 
            }
        }
        printf("\nRequired middle element: %d", value);
    }
}

void peekHighestElement(stack *s)
{
    int max;
    if (s-> top== -1)
    {
        printf("\nStack is empty");
        return;
    }

    else
    {
        max=0;
        int i;
        for (i= s->top; i >=0; i--)
        {
            if (s-> data[i] > max)
            {
                max= s-> data[i];
            }
        }
        printf("\nHighest element of stack: %d", max);
    }
}