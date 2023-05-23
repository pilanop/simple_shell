#include "shell.h"

/**
 * tokenize - tokenizes a stirng
 * @lineptr: what the user inputed
 * Return: a ptr to arr of ptrs
 */

char **tokenize(char *lineptr)
{
	char **commands = NULL;
	char *tokening = NULL;
	size_t i = 0;
	int count = 0;

	if (lineptr == NULL)
		return (NULL);

	for (i = 0; lineptr[i]; i++)
	{
		if (lineptr[i] == ' ')
			count++;
	}
	if ((count + 1) == _strlen(lineptr))
		return (NULL);
	commands = malloc(sizeof(char *) * (count + 2));
	if (commands == NULL)
		return (NULL);

	tokening = strtok(lineptr, " \n\t\r");

	for (i = 0; tokening != NULL; i++)
	{
		commands[i] = tokening;
		tokening = strtok(NULL, " \n\t\r");
	}
	commands[i] = NULL;
	return (commands);
}

