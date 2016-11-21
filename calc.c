#include "holberton.h"
/**
 * __atoi - take string, and find number the starts at point n
 * @s: string to read
 * @n: position to begin reading number
 *
 * Return: Number parsed
 */
__atoi(char *s, int n)
{
	int number, i;

	i = number = 0;
	while (s[n + i] <= '9' && s[n + i] >= '0')
	{
		if (i > 0)
			number *= 10;
		number += s[n + i] - '0';
		i++;
	}
	return (number);
}
