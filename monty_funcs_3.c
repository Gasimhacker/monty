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
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n)
	{
		if (tmp->n < 0 || tmp->n > 127)
		{
			empty_stack(line_number, "can't pchar, value out of range");
			return;
		}
		else
			printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
