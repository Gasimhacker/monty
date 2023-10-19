#include "monty.h"

/**
 * nop - Do nothing
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void nop(__attribute__((unused))stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
}

/**
 * pchar - Print the character at the top of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
		empty_stack(line_number, "can't pchar, stack empty");
	else if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
		empty_stack(line_number, "can't pchar, value out of range");
	else
		printf("%c\n", (*stack)->next->n);
}

/**
 * pstr - Print the string starting at the top of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotate the stack to the top
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = (*stack)->next, *top = (*stack)->next;

	if (top && top->next)
	{
		while (tmp->next)
			tmp = tmp->next;

		(*stack)->next = top->next;
		top->next->prev = top->prev;
		tmp->next = top;
		top->next = NULL;
		top->prev = tmp;
	}
}

/**
 * rotr - Rotate the stack to the bottom
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = (*stack)->next, *top = (*stack)->next;

	if (top && top->next)
	{
		while (tmp->next)
			tmp = tmp->next;

		tmp->prev->next = NULL;
		tmp->prev = *stack;
		(*stack)->next = tmp;
		tmp->next = top;
		top->prev = tmp;
	}
}
