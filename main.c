#include "shell.h"

/**
* main - Entry point
* @argc: number of arguments
* @argv: pointer to arrays of pointers to strings
* Return: 0
*/
int main(int argc, char *argv[])
{

	char **buffer = NULL;
	(void)argc;

	while (1)
	{
		shell_interactive();
		buffer = get_command();
		if (buffer != NULL)
		{
			 exec_command(buffer, argv);

			free_memory(buffer);

		}
	}
	if (buffer != NULL)
	{
		print_env(buffer);
		free_memory(buffer);
	}
	if (!isatty(STDIN_FILENO))
	{
		buffer = get_command();
		if (buffer != NULL)
		{
			exec_command(buffer, argv);
			free_memory(buffer);
		}
	}
	free_env();
	free_memory(buffer);
	return (0);
}
