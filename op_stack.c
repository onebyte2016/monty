#include "monty.h"


void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_my_err(8, line_number, "add");

	sum = (*stack)->n + (*stack)->prev->n;

	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int result;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_my_err(8, line_number, "sub");
	(*stack)=(*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
