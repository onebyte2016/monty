#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct Stacking
{
        int n;
        struct Stacking *prev;
        struct Stacking *next;
} stack_ds;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_ds **stack, unsigned int line_number);
} instruction_t;

extern stack_ds *head;
typedef void (*op_func)(stack_ds **, unsigned int);

/*file operations*/
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_ds *create_node(int n);
void free_nodes(void);
void _print_stack(stack_ds **, unsigned int);
void push_to_stack(stack_ds **, unsigned int);
void enqueue(stack_ds **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void _print_pop(stack_ds **, unsigned int);
void pop_from_stack(stack_ds **, unsigned int);
void nop(stack_ds **, unsigned int);
void swap_nodes(stack_ds **, unsigned int);

/*Math operations with nodes*/
void add_nodes(stack_ds **, unsigned int);
void sub_nodes(stack_ds **, unsigned int);
void div_nodes(stack_ds **, unsigned int);
void mul_nodes(stack_ds **, unsigned int);
void mod_nodes(stack_ds **, unsigned int);

/*String operations*/
void print_char(stack_ds **, unsigned int);
void print_str(stack_ds **, unsigned int);
void rotl(stack_ds **, unsigned int);

/*Error hanlding*/
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);
void rotr(stack_ds **, unsigned int);

#endif
