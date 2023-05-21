#include "shell.h"

int sh_exit(char **args);

char *builtin_str[] = {"exit"};

int (*builtin_func[])(char **) = {&sh_exit};

/**
 * sh_num_builtins - size of builtin_str
 * Return: size
 */

int sh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

/**
 * sh_exit - Builtin function to exit the shell.
 * @args: List of arguments. Not examined.
 * Return: Always returns 200, to terminate execution.
 */
int sh_exit(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * _fork_fun - Creates a child process to execute a command.
 * @arg: Command and arguments.
 * @av: Name of the program.
 * @env: Environment variables.
 * @lineptr: Command line entered by the user.
 * @np: Process ID.
 * @c: Flag to indicate whether to free the first argument.
 * Return: 0 on success, or an error code on failure.
 */
int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{

	pid_t child_pid;
	int status, i = 0;
	char *format = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (i = 0; i < sh_num_builtins(); i++)
	{
		if (_strcmp(arg[0], builtin_str[i]) == 0)
			return (builtin_func[i](arg));
	}
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		return (status);
	}
	return (0);
}
