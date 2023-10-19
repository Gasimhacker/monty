#include "monty.h"
#include "init.h"
/**
 * get_op_func - Choose the right function to execute
 * @op_code: The code that should tell us which function to choose
 *
 * Return: If the function is found - A pointer to the chosen function
 *	   Otherwise - NULL
 */
op_func *get_op_func(char *op_code)
{
	int i;
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"#", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(op_funcs[i].opcode, op_code) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * is_empty - Check if the line contains delemiters only
 * @line: The line to check
 * @delim: The delimeters
 *
 * Return: If the line contains delemiters only - 1
 *	   Otherwise 0
 */
int is_empty(char *line, char *delim)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (line[i] == delim[j])
				break;
		}
		if (delim[j] == '\0')
			return (0);
	}

	return (1);
}


/**
 * run_interpreter - Run the interpreter after openining the file
 * @script: The file pointer
 *
 * Return: void
 */
void run_interpreter(FILE *script)
{
	int line_num = 0, *exit_status = get_exit_status();
	size_t len;
	char *line = NULL;
	op_func *func;
	stack_t *stack = NULL;

	*exit_status = init_stack(&stack);

	if (*exit_status == EXIT_FAILURE)
		return;

	while ((getline(&line, &len, script) != -1))
	{
		line_num++;
		if (is_empty(line, DELIMS) || line[0] == '#')
			continue;
		op_tokens = split_string(line, DELIMS);
		if (op_tokens == NULL)
		{
			free_stack(stack);
			malloc_error();
			break;
		}

		func = get_op_func(op_tokens[0]);
		if (func == NULL)
		{
			op_not_found(op_tokens[0], line_num);
			clean(op_tokens);
			break;
		}
		func(&stack, line_num);
		clean(op_tokens);
		if (*exit_status == EXIT_FAILURE)
			break;
	}
	free_stack(stack);
	free(line);
}
