#ifndef MONTY_H
#define MONTY_H

#define STACK 1
#define QUEUE 2
#define DELIMS " \n\t"
#define _GNU_SOURCE

/* "Inclusions" */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* "Structures" */
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


typedef void op_func(stack_t **stack, unsigned int line_number);

/* "Global variables" */
extern char **op_tokens;


/* "String helpers" */
/**
 * split_string - Split the string into an array of tokens
 * @str: The string to split
 * @delimiter: A string containing all the posibble delimiters
 *
 * Return: An array of splitted words
 *	   Or "NULL" on failure
 */
char **split_string(const char *str, const char *delimiter);
/**
 * is_atoi - Check if a string contains only numbers
 *
 * Return: If it is a number - 1
 *	   Otherwise - 0
 */
int is_atoi(void);

/* "Memory helpers" */
/**
 * _realloc - Reallocate memory block using malloc and free
 *	      and copy the content of ptr to the newly allocated space,
 *	      in the range from the start of ptr up to
 *	      the minimum of the old and new sizes.
 *	      If new_size > old_size, the "added" memory
 *	      should not be initialized
 * @ptr: A pointer to the memory previously allocated with a call to malloc:
 *	 "malloc(old_size)"
 * @old_size: The size, in bytes, of the allocated space for ptr
 * @new_size: The size, in bytes, of the new memory block
 *
 * Return: A pointer to the allocated memory,
 *	   if new_size == old_size,do not do anything and return ptr
 *	   If new_size is equal to zero, and ptr is not NULL,
 *	   then the call is equivalent to free(ptr). Return NULL
 *	   If malloc fails, then _realloc returns NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/**
 * clean - Free an array of pointers
 * @array: The array to be freed
 *
 * Return: void
 */
void clean(char **array);
/**
 * get_exit_status - Save the last exit code
 *
 * Return: A pointer to the last saved exit code
 */
int *get_exit_status(void);
/**
 * init_stack - Initialize the stack
 * @stack: A pointer to the stack we want to initialize
 *
 * Return: If the stack is initialized correctly - EXIT_SUCCESS
 *	   Otherwise - EXIT_FAILURE
 */
int init_stack(stack_t **stack);
/**
 * free_stack - Free a dlistint_t list
 * @stack: A pointer to stack to be freed
 *
 * Return: void
 */
void free_stack(stack_t *stack);


/* "Error handling" */

/**
 * malloc_error - Print an error message if we can't allocate memory
 *
 * Return: void
 */
void malloc_error(void);
/**
 * argc_error - Print an error message if the argc is not 1
 *
 * Return: void
 */
void argc_error(void);
/**
 * cant_open - Print an error message if the file cannot be opened
 * @file: The file path
 *
 * Return: Void
 */
void cant_open(char *file);
/**
 * op_not_found - Print an error message if the op_code is invalid
 * @op_code: The invalid code
 * @line_num: The line containing the invalid code
 *
 * Return: Void
 */
void op_not_found(char *op_code, int line_num);
/**
 * no_number_found -  Print an error message if the argument
 *		      passed is not an integer or if there is no argument given
 * @line_number: The number of the line in the file
 *
 * Return: void
 */
void no_number_found(int line_number);
/**
 * empty_stack - Print an error message if the stack is empty
 * @line_number: The number of the line in the file
 * @err_msg: This message will be printed to the stderr
 *
 * Return: Void
 */
void empty_stack(int line_number, char *err_msg);
/**
 * zero_division - Print an error message if there is a division by zero
 * @line_number: The number of the line in the file
 *
 * Return: Void
 */
void zero_division(int line_number);

/* "Monty functions" */
/**
 * run_interpreter - Run the interpreter after openining the file
 * @script: The file pointer
 *
 * Return: void
 */
void run_interpreter(FILE *script);
/**
 * push - Push an element to the stack or queue
 * @stack: The stack
 * @line_number: This is used for printing error messages
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_number);
/**
 * pall - Print all the elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for ptinting error messages
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number);
/**
 * pint - Print the elements at the top of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for ptinting error messages
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number);
/**
 * pop - Remove the elements at the top of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number);
/**
 * swap - Swap the top two elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number);
/**
 * add - Add the top two elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number);
/**
 * nop - Do nothing
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number);
/**
 * sub - Subtract the top two elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number);
/**
 * _div - Divide the the second top element of the
 *	 stack by the top element of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number);
/**
 * mul - Multiply the top two elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number);
/**
 * mod - Compute the rest of the division of the second top element
 *	 of the stack by the top element of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number);
/**
 * pchar - Print the character at the top of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number);
/**
 * pstr - Print the string starting at the top of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void pstr(stack_t **stack, unsigned int line_number);
/**
 * rotl - Rotate the stack to the top
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_number);
/**
 * rotr - Rotate the stack to the bottom
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_number);


#endif /* MONTY_H */
