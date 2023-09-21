#include "shell.h"

/**
* itoa - converts the number to string
* @number: the number that need to be converted
* Return: pointer to the string or NULL otherwise
*/

char *itoa(int number)
{

	char *buffer;

	int len = _lenNum(number);

	int i = 0, negative = 0, num, start, end;

	buffer = malloc(sizeof(char) * (len + 2));
	if (buffer == NULL)
	{
		return (NULL);
	}
	if (number < 0)
	{
		negative = 1;
		number = -number;
		buffer[i] = '-';
		i++;
	}
	if (number == 0)
	{
		buffer[i] = '0';
		i++;
	}
	else
	{
		while (number > 0)
		{
			num = number % 10;
			buffer[i] = num + '0';
			number = number / 10;
			i++;
		}
	}
	start = negative ? 1 : 0;
	end = i - 1;
	reverse_string(buffer + start, end);
	buffer[i] = '\0';
	return (buffer);
}


/**
* _lenNum - count the length of number
* @num: the number
* Return: the length
*/

int _lenNum(int num)
{
	int count = 0;

	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

/**
* _atoi - function that convert a string to an integer.
* @s: the pointer that store the value of the string
* Return: dest
*/

int _atoi(char *s)
{
	int num = 0;

	int i = 0;

	int sign = 1;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign *= -1;
			i++;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			num *= 10;
			num += s[i] - '0';
			i++;
		}
		else
		{
			break;
		}
	}

	return (num * sign);
}
