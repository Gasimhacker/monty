#include "monty.h"

/**
 * malloc_error - Print an error message if we can't allocate memory
 *
 * Return: Void
 */
void malloc_error(void)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "Error: malloc failed\n");
	*exit_status = EXIT_FAILURE;
}

/**
 * argc_error - Print an error message if the argc is not 1
 *
 * Return: Void
 */
void argc_error(void)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "USAGE: monty file\n");
	*exit_status = EXIT_FAILURE;
}

/**
 * cant_open - Print an error message if the file cannot be opened
 * @file: The file path
 *
 * Return: Void
 */
void cant_open(char *file)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "Error: Can't open file %s\n", file);
	*exit_status = EXIT_FAILURE;
}

/**
 * op_not_found - Print an error message if the op_code is invalid
 * @op_code: The invalid code
 * @line_num: The line containing the invalid code
 *
 * Return: Void
 */
void op_not_found(char *op_code, int line_num)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
	*exit_status = EXIT_FAILURE;
}

/**
 * no_number_found -  Print an error message if the argument
 *		      passed is not an integer or if there is no argument given
 * @line_number: The number of the line in the file
 *
 * Return: void
 */
void no_number_found(int line_number)
{
	int *exit_status = get_exit_status();

	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	*exit_status = EXIT_FAILURE;
}
