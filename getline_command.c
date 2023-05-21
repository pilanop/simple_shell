#include "shell.h"

/**
 * _getline_command -  GEts inputs
 * Return: The input.
 */

char *_getline_command(void)
{
	char *input_string = NULL;
	size_t input_size = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&input_string, &input_size, stdin) == -1)
	{
		free(input_string);
		return (NULL);
	}

	return (input_string);
}
