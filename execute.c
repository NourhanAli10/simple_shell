#include "shell.h"

/**
* exec_command - function that execute commands
* @tokens: commands to execute
* @argv: an array contain the program name
* Return: status
*/

int exec_command(char **tokens, char *argv[])
{
	pid_t new_process;
	char *final_command;

	int status, exit_status;

	final_command = handle_command(tokens, argv);
	if (final_command)
	{
		new_process = fork();
		if (new_process == -1)
		{
			return (-1);
		}
		if (new_process == 0)
		{
			exceve_command(final_command, tokens, argv);
		}
		else if (new_process > 0)
		{
			waitpid(new_process, &status, WUNTRACED);
			while (!WIFEXITED(status) && !WIFSIGNALED(status))
			{
				waitpid(new_process, &status, WUNTRACED);
			}
			exit_status = handle_exit_status(status);
		}
	}
	return (exit_status);
}

/**
* handle_command - function to get the final command
* @tokens: commands after spliting
* @argv: program name
* Return: the final command
*/

char *handle_command(char **tokens, char *argv[])
{
	char *command = tokens[0];

	char *final_command;

	char *error;

	if (tokens == NULL || tokens[0] == NULL)
	{
		return (NULL);
	}

	if (command[0] != '/' && command[0] != '.')
	{
		final_command = get_path(command);
		if (final_command == NULL)
		{
			error = handle_error(argv, tokens);
			if (error == NULL)
			{
				free_memory(tokens);
			}
			exit(127);
		}
	}
	else
	{
		final_command = command;
	}
	return (final_command);
}

/**
* handle_exit_status - handle exit status
* @status: status
* Return: exit status
*/

int handle_exit_status(int status)
{
	int exit_status;

	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
	}
	else if (WIFSIGNALED(status))
	{
		exit_status = WTERMSIG(status);
	}
	else
	{
		exit_status = 0;
	}

	return (exit_status);
}


/**
* exceve_command - function that execute command
* @command: final command
* @tokens: list of commands after spliting
* @argv: program name
*/

void exceve_command(char *command, char **tokens, char *argv[])
{

	if (execve(command, tokens, environ) == -1)
	{
		handle_error(argv, tokens);
		exit(127);
	}
}
