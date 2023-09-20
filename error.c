#include "shell.h"
/**
* handle_error - print error when command or file are not found
* @argv: array that hold the name of the program
* @command: command that will help to show the error
* Return: a pointer to the error
*/
char *handle_error(char *argv[], char **command)
{
	char *prog_name;

	int prog_len;

	int command_len, counter = 1;

	char *line_error, *error;

	int len, total_length;

	prog_name = argv[0];
	prog_len = _strlen(prog_name);
	command_len = _strlen(command[0]);
	line_error = _itoa(counter);
	total_length = prog_len + command_len + _strlen(line_error) + 17;
	error = malloc(total_length + 1);
	if (error == NULL)
	{
		return (NULL);
	}
	_strcopy(error, prog_name);
	_strcat(error, ": ");
	_strcat(error, line_error);
	_strcat(error, ": ");
	_strcat(error, command[0]);
	_strcat(error, ": not found\n");
	free(line_error);
	len = _strlen(error);
	write(STDERR_FILENO, error, len);
	return (error);
}
