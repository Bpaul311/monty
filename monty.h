#ifndef MONTY_H
#define MONTY_H
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#define Buffsize 4096

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_variable - golbal variables
 * @file: file name
 * @buffer: Getline buffer
 * @temp: Getline counter
 * @dictionary: instruction dictionary
 * @head: pointer to list
 * @line_cnt: Stores file current line
 * @data_structure: Program configuration stack or queue
 */
typedef struct glob_variable
{
	FILE *file;
	char *buffer;
	size_t temp;
	instruction_t *dictionary;
	stack_t *head;
	unsigned int line_cnt;
	int data_structure;
} vars;

extern vars var;




int is_num(char *string);
stack_t *node_add(stack_t **stack, const int n);
stack_t *add_last_node(stack_t **stack, const int n);
size_t print_stack(const stack_t *stack);
void pall(stack_t **stack, unsigned int line_cnt __attribute__((unused)));
void print_err(char *argv);
void print_e(void);
void free_data(void);
void queue(stack_t **stack, unsigned int line_cnt);
void pstr(stack_t **stack, unsigned int line_cnt __attribute__((unused)));
void pchar(stack_t **stack, unsigned int line_cnt);
int call_function(vars *var, char *opcode);
instruction_t *create_instruction();
int initialise(vars *var);
int is_digit(char *str);
void rotl(stack_t **stack, unsigned int line_cnt __attribute__((unused)));
void rotr(stack_t **stack, unsigned int line_cnt __attribute__((unused)));
void sub(stack_t **stack, unsigned int line_cnt);
void divide_stack(stack_t **stack, unsigned int line_cnt);
void prod(stack_t **stack, unsigned int line_cnt);
void mod(stack_t **stack, unsigned int line_cnt);
void pop(stack_t **stack, unsigned int line_cnt);
void swap(stack_t **stack, unsigned int line_cnt);
void push(stack_t **stack, unsigned int line_cnt);
void add(stack_t **stack, unsigned int line_cnt);
int is_ascii(int a);
void stack(stack_t **stack, unsigned int line_cnt);
void pint(stack_t **stack, unsigned int line_cnt);
#endif
