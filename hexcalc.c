#include "holberton.h"
#include <stdio.h>
/**
 * _litoh - convert a long int into a hex string
 * @x: int to convert to hex
 */
char *_litoh(long int x)
{
	char *s;
	int tmp, i;

	i = 0;
	s = malloc(16 * sizeof(char));
	
	while (x != 0)
	{
		tmp = x % 16;
		/* convert int to char */
		if (tmp < 10)
			tmp += '0';
		else
			tmp += 'a' - 10;

		s[i++] = tmp;
		x /= 16;
	}
	s[i] = '\0';
      printf("Hex conversion: %s\n", s);
	_revstr(s);
	printf("Hex conversion: %s\n", s);
	return (s);
}
