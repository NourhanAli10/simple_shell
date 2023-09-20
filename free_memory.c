#include "shell.h"

/**
* free_memory - function that free buffer
* @buffer: the buffer need to be freed
*/

void free_memory(char **buffer)
{
	int i;

	for (i = 0; buffer[i] != NULL; i++)
	{
		free(buffer[i]);
	}

	free(buffer);
}




/**
* free_env - function that free environ
*/

void free_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		free(environ[i]);
	}

	free(environ);
}
