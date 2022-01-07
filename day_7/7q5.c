#include <stdio.h>
#include <stdlib.h>
# define N 5

struct queue
{
int s[N];
int front,rear;
}st;


int full()
{
if(((st.front == 0) && (st.rear == N - 1)) || (st.rear == st.front -1))
return 1;
else return 0;
}


int empty()
{
if(st.front == -1)
return 1;
else return 0;
}


void enqueue(int num)
{
if(full())
{
printf("\nQUEUE IS FULL\n");
}
else
{
if(st.front == -1)
{
st.front = 0;
}
st.rear = ((st.rear + 1) % N);
st.s[st.rear]=num;
}}

int dequeue()
{
int x;
if(empty())
{
printf("\nQUEUE IS EMPTY\n");
}
else
{
x = st.s[st.front];
if(st.front==st.rear)
st.front=st.rear=-1;
else
st.front = ((st.front + 1) % N);
}
printf("\nDequeued Element : %d",x);
}

void display()
{
int i;
if(empty())
printf("\nEMPTY QUEUE\n");
else
{

printf("\nQUEUE ELEMENTS : ");
for(i=st.front;i!=st.rear;i = ((i+1)%N))
printf("%d ",st.s[i]);
printf("%d ",st.s[i]);

}}

int main()
{
int num,choice;
st.front = st.rear = -1;
while(1)
{
printf("\n\nQUEUE OPERATIONS\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n\n");
scanf("%d",&choice);
switch (choice)
{
case 1:
if(full())
{
printf("\nQUEUE IS FULL\n");
}
else
{
printf("\nEnter item : ");
scanf("%d",&num);
enqueue(num);
}
break;
case 2:
if (empty())
{
printf("\nEMPTY QUEUE\n");
}
else
{
dequeue();
}
break;
case 3:
display();
int t;
printf("Please Enter 0 To Go To The Main Menu : ");
scanf("%d",&t);
break;
default: exit(0);
}}
return 0;
}