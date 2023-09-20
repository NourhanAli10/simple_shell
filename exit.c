#include "shell.h"

/**
 * exit_command - function that handle exit command
 * @command: commands to handle
 */

void exit_command(char **command)
{

	int i;
	int status;

	for (i = 0; command[i] != NULL; i++)
	{
		if (strncmp(command[i], "exit", _strlen("exit")) == 0 && !command[i + 1])
		{

			free_memory(command);
			exit(EXIT_SUCCESS);
		}
		else if (strncmp(command[i], "exit", _strlen("exit")) == 0 && command[i + 1])
		{
			status = atoi(command[i + 1]);
			free_memory(command);
			exit(status);
		}
	}
}
