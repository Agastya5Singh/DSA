#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    char data;
    struct node *next;
}*top=NULL;

 void push(char x)
 {
     struct node *t;
     t=(struct node *)malloc(sizeof(struct node ));
     t->data=x;
     t->next=top;
     top=t;
 }
 char pop(void)
 {
     struct node *t=top;
     char p=t->data;
     top=top->next;
     free(t);
     return p;
 }
 void display(struct node *t)
 {
     if(t==NULL)
     {
         printf("\nStack Is Empty");
     }
     else
     {
         while(t)
         {
             printf("%c", t->data);
             printf("\n");
             t=t->next;

         }
     }
 }

 int pre(char x)
 {
     if(x=='+' || x=='-')
     return 1;
     else if(x=='/' || x=='*')
     return 2;
     return 0;
 }
 int isoperand(char x)
 {
     if(x=='+'||x=='-'||x=='*'||x=='/' )
     return 0;
     else
     return 1;
 }
 char *infix_to_postfix(char *infix)
 {
     int i=0,j=0;
     char *postfix;
     int len=strlen(infix);
     postfix=(char*)malloc((len+2)*sizeof(char));
     while(infix[i]!='\0')
     {
         if(isoperand(infix[i]))
         {
             postfix[j++]=infix[i++];
         }
         else
         {
             if(pre(infix[i])>pre(top->data))
             {
                 push(infix[i]);
                 i++;
             }
             else
             {
                 postfix[j]=pop();
             }
         }
         
     }
     while(top)
     {
         postfix[j++]=pop();
     }
     postfix[j]='\0';
     return postfix;

 }
 int main()
{
    char *infix="a*b+c-d/e";
     push('#');
    char *postfix=infix_to_postfix(infix);
    printf("%s ",postfix);
   

}