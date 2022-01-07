#include <stdio.h>
#include <stdlib.h>

struct node
{
  int cof;
  int pow;
  struct node *next;
};

void create(struct node **h)
{
  int n, c, p;
  struct node *ptr;

  printf("Enter number of terms: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    struct node *cur;
    cur = malloc(sizeof(struct node));
    printf("Enter the coefficient of %d term: ", i + 1);
    scanf("%d", &cur->cof);
    printf("Enter the power of %d term: ", i + 1);
    scanf("%d", &cur->pow);
    cur->next = NULL;
    if (*h == NULL)
    {
      *h = cur;
      ptr = cur;
    }
    else
    {
      ptr->next = cur;
      ptr = cur;
    }
  }
}

void display(struct node *p)
{
  if (p == NULL)
  {
    printf("\nThe List Is Empty :(");
  }
  else
  {
    while (p != NULL)
    {
      printf("%dx^", (p)->cof);
      printf("%d ", (p)->pow);
      p = (p)->next;
      if (p != NULL)
        printf("+");
    }
  }
}

int main()
{

  struct node *h1 = NULL;
  struct node *ptr = NULL;

  create(&h1);
  printf("\nThe polynomial expression: ");
  display(h1);
}  

