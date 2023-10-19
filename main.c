#include "monty.h"


/**
 * main - Run the monty interpreter
 * @argc: Number of arguments
 * @argv: The arguments array
 *
 * Return: The last exit status
 */
int main(int argc, char **argv)
{
	int *exit_status = get_exit_status();
	FILE *script = NULL;

	if (argc != 2)
	{
		argc_error();
	}
	else
	{
		script = fopen(argv[1], "r");
		if (script == NULL)
		{
			cant_open(argv[1]);
		}
		else
		{
			run_interpreter(script);
			fclose(script);
		}
	}

	return (*exit_status);
}
