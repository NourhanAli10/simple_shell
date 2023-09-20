#include "shell.h"

/**
 * get_command - function that take comamnd from user
 * Return: the command after tokinze it
 */
char **get_command()
{

	char *buffer_add = NULL;
	size_t buf_size = 0;
	ssize_t bytes;
	char **result;

	const char *delimiter = " \t\n";

	bytes = getline(&buffer_add, &buf_size, stdin);

	if (bytes == 0)
	{
		return (NULL);
	}
	if (bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			free(buffer_add);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(buffer_add);
			exit(EXIT_SUCCESS);
		}
	}

	buffer_add[bytes - 1] = '\0';

	result = tokenize_command(buffer_add, bytes, delimiter);

	exit_command(result);
	free(buffer_add);
	return (result);
}

/**
 * shell_interactive - to check if shell is interactive or not
 */
void shell_interactive(void)
{
	char *prompt = "$ ";

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, 2);
	}
}
