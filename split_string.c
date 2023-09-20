#include "shell.h"

/**
* tokenize_command - function that split the shell commands
* into words
* @buffer: command
* @n: bytes of buffer
* @delimiter: seperator
* Return: pointer to pointer to strings
*/

char **tokenize_command(char *buffer, ssize_t n, const char *delimiter)
{
	char *token;

	int token_count = 0;

	char **str_arr;

	if (buffer == NULL)
	{
		return (NULL);
	}

	str_arr = malloc(sizeof(char *) * (n + 1));

	if (str_arr == NULL)
	{
		free(buffer);
		perror("memory allocation error");
		return (NULL);
	}

	token = strtok(buffer, delimiter);
	while (token != NULL)
	{
		str_arr[token_count] = my_strdup(token);
		token = strtok(NULL, delimiter);
		token_count++;
	}

	str_arr[token_count] = NULL;

	return (str_arr);
}
