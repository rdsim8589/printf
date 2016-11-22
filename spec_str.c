#include "holberton.h"
#include <stdio.h>
/**
 * spec_s - sends va_arg with appropriate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_s(buffer *b_r, tags *t)
{
	char *hold;
	char *b_str;
	int i, j, k, l, minus, b_str_size, hold_len;
	/* get arg from va_arg and store */
	hold = va_arg(b_r->ap, char *);
	minus = i = 0;
	/*check the precision tag*/
	printf("t->prec: %d\n", t->prec);
	hold_len = str_len(hold);
	/* if width if found */
	if (t->width > hold_len)
	{
		b_str_size = t->width;
		b_str = malloc(b_str_size * sizeof(char *));
		/*if - flag is found */
		for (k = 0; t->flags[k] != '\0'; k++)
		{
			if (t->flags[k] == '-')
				minus = 1;
		}
		/*- flag found, hold left most */
		if (minus == 1)
		{
			while (i < hold_len)
				b_str[i] = hold[i++];
			while (i < b_str_size)
				b_str[i++] = ' ';
		}
		/* - flag not found, hold right most*/
		else
		{
			while (i < b_str_size - hold_len)
				b_str[i++] = ' ';
			while (i < b_str_size)
				b_str[i++] = hold[l++];
		}
	}
	/* no width given */
	else
	{
		b_str_size = hold_len;
		b_str = malloc(b_str_size * sizeof(char));
		while (i < b_str_size)
			b_str[i] = hold[i++];
	}
	for (j = 0; j < b_str_size; j++)
		b_r->buf[b_r->bp++] = b_str[j];
	free(b_str);
}
/**
 * str_len - find the str len
 * @str: a pointer to a str
 *
 * Return: length of string
 */
int str_len(char *str)
{
	int i;

	i = 0;
	while (str[i++] != '\0')
		;
	return (i);
}
