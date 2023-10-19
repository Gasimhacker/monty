#include "monty.h"

/**
 * init_stack - Initialize the stack
 * @stack: A pointer to the stack we want to initialize
 *
 * Return: If the stack is initialized correctly - EXIT_SUCCESS
 *	   Otherwise - EXIT_FAILURE
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));

	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->next = NULL;
	s->prev = NULL;

	*stack = s;
	return (EXIT_SUCCESS);
}

/**
 * free_stack - Free a dlistint_t list
 * @stack: A pointer to stack to be freed
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;

	while (stack)
	{
		tmp = stack->next;
		free(stack);

		stack = tmp;
	}
}
