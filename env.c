#include "shell.h"

/**
 * get_env - get the env value
 * @name: the name of the env variable that will get
 * Return: a pointer to the value
 */

char *get_env(char *name)
{

	int i = 0;

	int len = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(name, environ[i], len) == 0)
		{
			return (environ[i]);
		}
	}

	return (NULL);
}

/**
 * print_env - print all environment variables
 * @command: the command from the user
 * Return: nothing
 */

void *print_env(char **command)
{
	int i;

	int len = _strlen("env");

	if (command == NULL || command[0] == NULL)
	{
		return (0);
	}

	if (strncmp(command[0], "env", len) == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
		}

		free_env();
	}

	return (0);
}

