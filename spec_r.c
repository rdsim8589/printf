#include "holberton.h"
#include <stdio.h>
/**
 * _spec_r - sends va_arg with appropriate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_r(buffer *b_r, tags *t)
{
	char *hold, *holdr;
	char *b_str;
	int i, j, k, l, minus, b_str_size, hold_len;
	hold = va_arg(b_r->ap, char *);
	minus = i = l = 0;
	holdr = malloc(1024);
	while (hold[i] != '\0')
		holdr[i] = hold[i], i++;
	holdr[i] = '\0';
	_revstr(holdr);
	i = 0;
	hold_len = str_len(holdr);
	if (t->prec != -1 && t->prec < hold_len)
		hold_len = t->prec;
	/* if width if found */
	if (t->width > hold_len)
	{
		b_str = _str_whelp(t, holdr, hold_len);
		b_str_size = t->width;
	}
	/* no width given */
	else
	{
		b_str_size = hold_len;
		b_str = malloc(b_str_size * sizeof(char));
		while (i < b_str_size)
			b_str[i] = holdr[i], i++;
	}
	for (j = 0; j < b_str_size; j++)
		b_r->buf[b_r->bp++] = b_str[j];
	free(b_str);
	free(holdr);
}
