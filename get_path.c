#include "shell.h"

/**
* get_path - function that help to get path from env
* @command: the buffer
* Return: the command
*/

char *get_path(char *command)
{
	char *path;

	char **path_arr;

	const char *delimiter = ":";

	char *result = NULL;

	char *path_v3;

	int num_count = 0;



	path = get_env("PATH");
	if (path == NULL)
	{
		return (NULL);
	}
	num_count = count_token(path);
	path_v3 = malloc(_strlen(path) + 1);
	_strcopy(path_v3, path);

	path_arr = tokenize_command(path_v3, num_count, delimiter);
	free(path_v3);
	result = full_path(path_arr, command);
	free_memory(path_arr);
	return (result);
}

/**
* full_path - function that help to get path from env
* @path: the path
* @command: the command
* Return: the full path with command
*/

char *full_path(char **path, char *command)
{
	int i;

	int path_length;

	char *full_path;

	struct stat status;
	int total_length;

	char *mark = "/";

	int command_len = _strlen(command);

	i = 0;
	while (path[i] != NULL)
	{
		path_length = _strlen(path[i]);
		total_length = path_length + command_len + 2;
		full_path = malloc(total_length);
		if (full_path == NULL)
		{
			return (NULL);
		}
		_strcopy(full_path, path[i]);
		_strcat(full_path, mark);
		_strcat(full_path, command);

		if (stat(full_path, &status) == 0 && access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		else
		{
			free(full_path);
			i++;
		}
	}
	return (NULL);
}

/**
* count_token - count the number of tokens
* @path: the path
* Return: number of tokens
*/

int count_token(char *path)
{
	char *path_v2;

	int num_count = 0;

	char *token;

	const char *delimiter = ":";

	path_v2 = malloc(_strlen(path) + 1);
	_strcopy(path_v2, path);
	token = strtok(path_v2, delimiter);
	while (token != NULL)
	{
		num_count++;
		token = strtok(NULL, delimiter);
	}
	free(path_v2);

	return (num_count);


}
