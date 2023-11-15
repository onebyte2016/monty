#include "monty.h"

/**
 * add_nodes - addition of the two last tow element.
 * @error_my_err - handle errors
 * (8)
 */ 
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

/**
 * The opcode nop doesn’t do anything.
 * return: void
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_nodes - subtraction of the two last tow element.
 * @error_my_err - handle errors
 * (8)
 */
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
