#include "holberton.h"
#include <stdio.h>
/**
 * _spec_p - sends va_arg with appropirate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_p(buffer *b_r, tags __attribute__((unused))(*t))
{
	long int hold;
	char *s;
	int i;

	s = va_arg(b_r->ap, void *);

	if (s == NULL)
	{
		s = "(nil)";
		for (i = 0; s[i] != '\0'; i++)
			b_r->buf[b_r->bp++] = s[i];
	}
	else
	{
		hold = (long int)s;
		s = _int_to_hexstr(hold);

		b_r->buf[b_r->bp++] = '0';
		b_r->buf[b_r->bp++] = 'x';

		for (i = 0; s[i] != '\0'; i++)
			b_r->buf[b_r->bp++] = s[i];
		free(s);
	}
}
