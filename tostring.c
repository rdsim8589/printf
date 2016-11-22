#include "holberton.h"
#include <stdio.h>
/**
 * int_to_str - convert an int into it's absolute value string
 * @n: number to convert
 */
char *int_to_str(int n)
{
	char *s;
	int tmp, i;

	tmp = i = 0;
	s = malloc(11 * sizeof(char));
   
	if (n == 0)
		s[i] = '0';
	while (n != 0)
	{

		s[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	s[i] = '\0';
	_revstr(s);
	return (s);
}
