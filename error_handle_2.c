#include "monty.h"

/**
 * cannot_pint - Print an error message if the stack is empty
 * @line_number: The number of the line in the file
 *
 * Return: Always EXIT_FAILURE
 */
int cannot_pint(int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}
