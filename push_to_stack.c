#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 1000

typedef struct {
	int stack[STACK_SIZE];
	int top;
} Stack;

void initStack(Stack *s)
{
	s->top = -1;
}

void push(Stack *s, int value, int line_number)
{
	s->stack[++s->top] = value;
}

void pall(Stack *s, int line_number)
{
	if (s->top == -1)
	{
		return;
	}

	for (int i = s->top; i >= 0; i--)
	{
		printf("%d\n", s->stack[i]);
	}
}
