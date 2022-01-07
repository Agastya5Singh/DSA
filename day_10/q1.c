#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    struct node *rchild;
    int data;
}*root=NULL;
void create(int input)
{   
    struct node *t;
    struct node *r;
    struct  node *p=root;
    if(p==NULL)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=input;
        t->lchild=t->rchild=NULL;
        root=t;
    }
    else
    {
        while(p)
        {   
            r=p;
            if(input < p->data)
            {
                p=p->lchild;
            }
            else if(input > p->data)
            {
                p=p->rchild;
            }
            else
            return;
        }
        t=(struct node *)malloc(sizeof(struct node));
        t->data=input;
        t->lchild=t->rchild=NULL;
        if(input < r->data)
            r->lchild=t;
            else
            r->rchild=t;
    }
}
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}
void preorder(struct node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
    
}
int height(struct node *p)
{
    int x,y;
    if(p==NULL)
    {
        return 0;
    }
    x=height(p->lchild);
    y=height(p->rchild);
    if(x>y)
    {
        return x+1;
    }
    else
    return y+1;
}
struct node *inprecessor(struct node *p)
{   
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}
struct node *insuccerssor(struct node *p)
{   
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}
struct node *delete(struct node *p,int key)
{
    struct node *q;
    if(p==NULL)
    return NULL;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
    }
    if(key < p->data)
    p->lchild=delete(p->lchild,key);
    else if(key > p->data )
    p->rchild=delete(p->rchild,key);
    else
    {
        if(height(p->lchild) > height(p->rchild))
        {
            q=inprecessor(p->lchild);
            p->data=q->data;
            p->lchild=delete(p->lchild,q->data);    
        }
        else
        {
            q=insuccerssor(p->rchild);
            p->data=q->data;
            p->rchild=delete(p->rchild,q->data); 
        }
    }
    return p;
}
int search(struct node *p,int key)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
         if(p->data == key)
        {
            return 0;
        }
        else
        return -1;
        inorder(p->rchild);
    }
}
int largest(struct node* p)
{
    if (p == NULL)
        return -1;
    int res = p->data;
    int llarge = largest(p->lchild);
    int rlarge = largest(p->rchild);
    if (llarge > res)
        res = llarge;
    if (rlarge > res)
        res = rlarge;
    return res;
}
int minValue(struct node* node) {
  struct node* current = node;
 
  while (current->lchild != NULL) {
    current = current->lchild;
  }
  return(current->data);
}
int main()
{
    int value;
    int wait;
    int val;
int choice = 0;
    P:
    printf("\n0 - Exit !!!");
    printf("\n1 - Create");
    printf("\n2 - In-Order Traversal");
    printf("\n3 - Pre-Order Traversal");
    printf("\n4 - Post-Order traversal");
    printf("\n5 - Search");
    printf("\n6 - Find Smallest Element");
    printf("\n7 - Find Largest Element");
    printf("\n8 - Deletion of Tree");
    printf("\nPlease Enter Your Choide : ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 0: 
        return 0;
        break;
        case 1:
        
        printf("\nPlease Enter The Value You Want To Enter : ");
        scanf("%d",&val);
        create(val);
        printf("\nplease Enter 0 To Go To The Main Menu : ");
        scanf("%d",&wait);
        if(wait == 0)

        {
            goto P;
        }
        else
        return 0;
        create(val);
        break;
        case 2:
        printf("\nInorder Traversal Is : \n");
        inorder(root);
          
        printf("\nplease Enter 0 To Go To The Main Menu : ");
        scanf("%d",&wait);
        if(wait == 0)

        {
            goto P;
        }
        else
        return 0;
        break;
        case 3:
        printf("\nPreorder Traversal Is : \n");
        preorder(root);
          
        printf("\nplease Enter 0 To Go To The Main Menu : ");
        scanf("%d",&wait);
        if(wait == 0)

        {
            goto P;
        }
        else
        return 0;
        break;
        case 4:
        printf("\nPost-Order Traversal Is : \n");
        postorder(root);
          
        printf("\nplease Enter 0 To Go To The Main Menu : ");
        scanf("%d",&wait);
        if(wait == 0)

        {
            goto P;
        }
        else
        return 0;
        break;
        case 5:
         
        printf("\nPlease Enter The Number You Want To Search In The Tree : ");
        scanf("%d",&val);
        if(search(root,val) == 0)
        printf("\nThe Number Is Present ");
        else
        printf("\nThe Number Is Not Present ");
          
        printf("\nplease Enter 0 To Go To The Main Menu : ");
        scanf("%d",&wait);
        if(wait == 0)

        {
            goto P;
        }
        else
        return 0;
        break;
        case 7:
        printf("\nThe Largest the Number In The Tree Is : %d",largest(root));
          
        printf("\nplease Enter 0 To Go To The Main Menu : ");
        scanf("%d",&wait);
        if(wait == 0)

        {
            goto P;
        }
        else
        return 0;
        break;
        case 6:
        printf("\nThe Smallest the Number In The Tree Is : %d",minValue(root));
          
        printf("\nplease Enter 0 To Go To The Main Menu : ");
        scanf("%d",&wait);
        if(wait == 0)

        {
            goto P;
        }
        else
        return 0;
        break;
        case 8:
         
        printf("\nPlease Enter The Number You Want To Delete In The Tree : ");
        scanf("%d",&val);
        delete(root,val);
          
        printf("\nplease Enter 0 To Go To The Main Menu : ");
        scanf("%d",&wait);
       goto P;
       break;
    }
}