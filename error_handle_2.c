#include "monty.h"

/**
 * empty_stack - Print an error message if the stack is empty
 * @line_number: The number of the line in the file
 * @err_msg: This message will be printed to the stderr
 *
 * Return: Void
 */
void empty_stack(int line_number, char *err_msg)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "L%d: %s\n", line_number, err_msg);
	*exit_status = EXIT_FAILURE;
}

/**
 * zero_division - Print an error message if there is a division by zero
 * @line_number: The number of the line in the file
 *
 * Return: Void
 */
void zero_division(int line_number)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "L%d: division by zero\n", line_number);
	*exit_status = EXIT_FAILURE;
}
