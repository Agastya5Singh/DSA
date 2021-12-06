#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int *s;
};
void create();      //Creating Stack    
void display();    //Display the Stack
void push();      //Enter A Value In Stack
int pop();       // Deleting A Value In Stack
int seek();     // Getting the Value Stored At A Particular Position

//create
void create(struct stack *st)
{
    st->top = -1;
    printf("\nPlease Enter The Size Of The Stack: ");
    scanf("%d", &st->size);
    st->s=(int*)malloc(st->size*sizeof(int));
}
//display
void display(struct stack st)
{
    if(st.top==-1)
    {
        printf("\nStack Is Empty Nothing To Display");
    }
    else
    {
    for(int i=st.top;i>-1;i--)
    {
        printf("%d ",st.s[i]);
        printf("\n");
    }
    }
}
//To Enter The Value of the Stack
void push(struct stack *st,int x)
{
    if(st->top>st->size-1)
    {   
        printf("\nStack Over Flow !");
    }
    else
    {
        st->top++;
        st->s[st->top]=x;
    }
}
//To Delete the Value In The Stack
int pop(struct stack *st)
{
    int delval=-1;
    if(st->top==-1)
    {
        printf("\nNo Values Left In Stack To Delete :( ");
    }
    else
    {
        delval=st->s[st->top];
        st->top--;
    }
    return delval;
}
void reverse(struct stack *st , struct stack *st1)
{
    while(st->top>-1)
    {
        push(st1,st->s[st->top]);
        pop(st);
    }
}
void main()
{
    system("cls");
    struct stack st;
    create(&st);
    struct stack st1;
    create(&st1);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    display(st);
    reverse(&st,&st1);
    printf("\nAfter Reverse\n");
    display(st1);

    

}