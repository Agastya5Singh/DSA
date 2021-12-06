#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Q4. WAP to convert an infix expression into its equivalent prefix notation.

typedef struct
{
	char data[10];
	int top;
} STACK;

STACK s1;

void init(STACK *S)
{
	S->top = -1;
}

void push(STACK *s, char v)
{
	s->top++;
	s->data[s->top] = v;
}

void pop(STACK *s, char *v)
{
	*v = s->data[s->top];
	s->top--;
}

int isEmpty(STACK s)
{
	if (s.top == -1)
	{
		return 1;
	}
	return 0;
}

int isOperand(char a)
{
	if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return 1;
	return 0;
}

int precedence(char a)
{
	int k = 0;
	switch (a)
	{
	case '+':
	case '-':
		k = 1;
		break;
	case '*':
	case '/':
		k = 2;
		break;
	}
	return k;
}

int isHL(char a, char b)
{
	if (precedence(a) > precedence(b))
		return 1;
	return 0;
}

void rev(char *str)
{
	int n = strlen(str);
	for (int i = 0, j = n - 1; i <= j; i++, j--)
	{
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '(')
		{
			str[i] = ')';
		}
		else if (str[i] == ')')
		{
			str[i] = '(';
		}
	}
}

void inToPre(char *inf, char *prf)
{
	int i = 0, k = 0;
	rev(inf);
	while (inf[i] != '\0')
	{
		if (isOperand(inf[i]))
		{
			prf[k] = inf[i];
			k++;
		}
		else if (inf[i] == '(')
		{
			push(&s1, '(');
		}
		else if (inf[i] == ')')
		{
			while (1)
			{
				char d;
				pop(&s1, &d);
				if (d == '(')
				{
					break;
				}
				prf[k++] = d;
			}
		}
		else
		{
			if (isEmpty(s1))
			{
				push(&s1, inf[i]);
			}
			else
			{
				char d;
				pop(&s1, &d);
				if (d == '(')
				{
					push(&s1, d);
					push(&s1, inf[i]);
				}
				else if (isHL(d, inf[i]))
				{
					prf[k++] = d;
					i--;
				}
				else
				{
					push(&s1, d);
					push(&s1, inf[i]);
				}
			}
		}
		i++;
	}
	while (!isEmpty(s1))
	{
		char d;
		pop(&s1, &d);
		prf[k++] = d;
	}
	prf[k] = '\0';
}

int main(void)
{
	char inf[100];
    printf("Enter an infix expression(without spaces in between): ");
	scanf("%s", inf);
	printf("Entered infix expression: %s\n", inf);
	init(&s1);
	char prf[100];
	inToPre(inf, prf);
	rev(prf);
	printf("\nPrefix expression: %s\n", prf);
}