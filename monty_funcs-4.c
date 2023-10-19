#include "monty.h"

/**
 * stack_mode - Change the mode to stack mode
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void stack_mode(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	(*stack)->n = STACK;
}

/**
 * queue_mode - Change the mode to queue mode
 * @stack: A pointer to the head of the stack
 * @line_number: This member is used for printing error messages
 *
 * Return: void
 */
void queue_mode(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	(*stack)->n = QUEUE;
}
