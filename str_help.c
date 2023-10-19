#include "monty.h"

/**
 * is_atoi - Check if a string contains only numbers
 *
 * Return: If it is a number - 1
 *	   Otherwise - 0
 */
int is_atoi(void)
{
	int i;

	for (i = 0; op_tokens[1][i]; i++)
	{
		if (op_tokens[1][i] == '-' && i == 0)
			continue;
		if (op_tokens[1][i] < '0' || op_tokens[1][i] > '9')
			return (0);
	}
	return (1);
}

/**
 * split_string - Split the string into an array of tokens
 * @str: The string to split
 * @delimiter: A string containing all the posibble delimiters
 *
 * Return: An array of splitted words
 *	   Or "NULL" on failure
 */
char **split_string(const char *str, const char *delimiter)
{
	char **words = NULL;
	char *str_copy = strdup(str);
	char *token = strtok(str_copy, delimiter);
	int count = 1;


	if (str == NULL)
		return (NULL);


	words = malloc(sizeof(char *));

	if (!words)
		return (NULL);

	words[0] = NULL;

	while (token != NULL)
	{
		words = _realloc(words, (count * sizeof(char *)),
				(count + 1) * sizeof(char *));

		if (!words)
			return (NULL);

		words[count - 1] = strdup(token);
		words[count] = NULL;

		count++;
		token = strtok(NULL, delimiter);
	}

	free(str_copy);

	return (words);
}
