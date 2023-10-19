#include "monty.h"

/**
 * empty_stack - Print an error message if the stack is empty
 * @line_number: The number of the line in the file
 * @err_msg: This message will be printed to the stderr
 *
 * Return: Always EXIT_FAILURE
 */
int empty_stack(int line_number, char *err_msg)
{
	fprintf(stderr, "L%d: %s\n", line_number, err_msg);
	return (EXIT_FAILURE);
}
