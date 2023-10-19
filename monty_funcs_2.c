#include "monty.h"

/**
 * add - Add the top two elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	if (top == NULL || top->next == NULL)
	{
		empty_stack(line_number, "can't add, stack too short");
		return;
	}
	top->next->n += (top->n);
	pop(stack, line_number);
}

/**
 * sub - Subtract the top two elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	if (top == NULL || top->next == NULL)
	{
		empty_stack(line_number, "can't sub, stack too short");
		return;
	}
	top->next->n -= (top->n);
	pop(stack, line_number);
}

/**
 * _div - Divide the the second top element of the
 *	 stack by the top element of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	if (top == NULL || top->next == NULL)
	{
		empty_stack(line_number, "can't div, stack too short");
		return;
	}
	if (top->n == 0)
	{
		zero_division(line_number);
		return;
	}
	top->next->n /= (top->n);
	pop(stack, line_number);
}

/**
 * mul - Multiply the top two elements of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	if (top == NULL || top->next == NULL)
	{
		empty_stack(line_number, "can't mul, stack too short");
		return;
	}
	top->next->n *= (top->n);
	pop(stack, line_number);
}

/**
 * mod - Compute the rest of the division of the second top element
 *	 of the stack by the top element of the stack
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top = (*stack)->next;

	if (top == NULL || top->next == NULL)
	{
		empty_stack(line_number, "can't mod, stack too short");
		return;
	}
	if (top->n == 0)
	{
		zero_division(line_number);
		return;
	}
	top->next->n %= (top->n);
	pop(stack, line_number);
}
