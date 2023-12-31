#include "shell.h"

/**
* _strlen - function returns the length of a string
* @string: the pointer refer to the string
* Return: length
*/

int _strlen(char *string)
{

	int len = 0;

	while (string[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
* _strcopy - function returns the length of a string
* @dest: the new variable hold new copy
* @src: the string to copy from
* Return: length
*/

char *_strcopy(char *dest, char *src)
{
	int i;

	int len = _strlen(src);

	for (i = 0; src[i] != '\0' && i < len; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}

/**
* my_strdup - function that allocate memory for string
* and copy it
* @source: the string
* Return: copy of the string
*/

char *my_strdup(char *source)
{
	size_t length;
	char *copy_string;

	if (source == NULL)
	{
		return (NULL);
	}

	length = _strlen(source);

	copy_string = malloc(sizeof(char) * (length + 1));

	if (copy_string == NULL)
	{

		return (NULL);
	}

	_strcopy(copy_string, source);

	return (copy_string);
}


/**
* reverse_string - prints a string in reverse
* @str: the string
* @length: length to be reversed
*/


void reverse_string(char *str, int length)
{
	int start = 0;

	int end = length - 1;

	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}


/**
* _strcat - concatenate two strings
* @dest: first string
* @src: string that i want to add
* Return: full string
*/

char *_strcat(char *dest, char *src)
{
	int i;

	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
