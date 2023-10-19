#include "monty.h"

/**
 * push - Push an element to the stack or queue
 * @stack: The stack
 * @line_number: This is used for printing error messages
 *
 * Return: Void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *tmp;

	if (op_tokens[1] == NULL)
	{
		no_number_found(line_number);
		return;
	}
	if (!is_atoi())
	{
		no_number_found(line_number);
		return;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		(malloc_error());
		return;
	}
	new->n = atoi(op_tokens[1]);
	if ((*stack)->n == STACK)
	{
		tmp = (*stack)->next;
		new->next = tmp;
		new->prev = *stack;
		if (tmp)
			(tmp)->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->prev = tmp;
	}
}


/**
 * pall - Print all the elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - Print the elements at the top of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
		empty_stack(line_number, "can't pint, stack empty");
	else
		printf("%d\n", (*stack)->next->n);

}

/**
 * pop - Remove the elements at the top of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	if (tmp == NULL)
	{
		empty_stack(line_number, "can't pop an empty stack");
		return;
	}
	(*stack)->next = tmp->next;
	tmp->prev = *stack;
	free(tmp);

}

/**
 * swap - Swap the top two elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;
	int tmp;

	if (top == NULL || top->next == NULL)
	{
		empty_stack(line_number, "can't swap, stack too short");
		return;
	}
	tmp = top->n;
	top->n = top->next->n;
	top->next->n = tmp;
}
