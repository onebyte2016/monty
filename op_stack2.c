#include "monty.h"

/**
 * div_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void div_nodes(stack_t **stack, unsigned int line_number)
{
	int div_result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_my_err(8, line_number, "div");

	if ((*stack)->n == 0)
		_my_err(9, line_number);
	(*stack) = (*stack)->next;
	div_result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = div_result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul_nodes - Adds the top two elements of the stack.
 * @top: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **top, unsigned int line_number)
{
	int mul_result;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		_my_err(8, line_number, "mul");

	(*top) = (*top)->next;
	mul_result = (*top)->n * (*top)->prev->n;
	(*top)->n = mul_result;
	free((*top)->prev);
	(*top)->prev = NULL;
}

/**
 * mod_nodes - Adds the top two elements of the stack.
 * @top: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **top, unsigned int line_number)
{
	int mod_result;

	if (top == NULL || *top == NULL || (*top)->next == NULL)
		_my_err(8, line_number, "mod");
	if ((*top)->n == 0)
		_my_err(9, line_number);
	(*top) = (*top)->next;
	mod_result = (*top)->n % (*top)->prev->n;
	(*top)->n = mod_result;
	free((*top)->prev);
	(*top)->prev = NULL;
}
