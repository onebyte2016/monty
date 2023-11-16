#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		_err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;
	stack_t *head = NULL;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * enqueue - Adds a node to the queue.
 * @top: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void enqueue(stack_t **top, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;
	stack_t *head = NULL;

	if (top == NULL || *top == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *top;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *top;
	(*top)->prev = tmp;
}
