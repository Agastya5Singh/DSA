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

void join(struct node **h1, struct node **h2)
{
  struct node *ptr = *h1;
  if (*h1 == NULL)
  {
    *h1 = *h2;
  }
  else
  {
    while (ptr->next)
    {
      if (ptr->next == NULL)
      {
        break;
      }
      ptr = ptr->next;
    }
    ptr->next = *h2;
  }
}

void add(struct node **h1)
{
  struct node *ptr = *h1;
  struct node *qtr;
  struct node *prev;
  for (ptr = *h1; ptr != NULL; ptr = ptr->next)
  {
    prev = ptr;
    qtr = ptr->next;
    while (qtr != NULL)
    {
      if (qtr->pow == ptr->pow)
      {
        ptr->cof = ptr->cof + qtr->cof;
        prev->next = qtr->next;
        free(qtr);
        qtr = prev;
      }
      prev = qtr;
      qtr = qtr->next;
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
  struct node *h2 = NULL;
  struct node *ptr = NULL;

  create(&h1);
  create(&h2);
  
  printf("\nThe polynomial expression 1: ");
  display(h1);
  printf("\nThe polynomial expression 2: ");
  display(h2);

  //addition of polynomials
  join(&h1, &h2);
  printf("The polynomial: ");
  display(h1);
  add(&h1);
  printf("\nThe simplified polynomial: ");
  display(h1);
}  
