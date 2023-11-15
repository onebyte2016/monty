#include "monty.h"


/**
 * push_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void push_to_stack(stack_ds **top, __attribute__((unused))unsigned int ln)
{
	stack_ds *tmp;

	if (top == NULL || *top == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *top;
		return;
	}
	tmp = head;
	head = *top;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * _print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void _print_stack(stack_ds **stack, unsigned int line_number)
{
	stack_ds *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_from_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_from_stack(stack_ds **stack, unsigned int line_number)
{
	stack_ds *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * _print_pop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _print_pop(stack_ds **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
