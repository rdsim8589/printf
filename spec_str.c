#include "holberton.h"
#include <stdio.h>
/**
 * _spec_s - sends va_arg with appropriate tags into buffer
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
	minus = i = l = 0;
	/*check the precision tag*/
	hold_len = str_len(hold);
	/* if prec is found, ignore width */
	if (t->prec != -1 && t->prec < hold_len)
		hold_len = t->prec;
	/* if width if found */
	if (t->width > hold_len)
	{
		b_str = _str_whelp(t, hold, hold_len);
		b_str_size = t->width;
	}
	/* no width given */
	else
	{
		b_str_size = hold_len;
		b_str = malloc(b_str_size * sizeof(char));
		while (i < b_str_size)
			b_str[i] = hold[i], i++;
	}
	for (j = 0; j < b_str_size; j++)
		b_r->buf[b_r->bp++] = b_str[j];
	free(b_str);
}
/**
 * _spec_S - sends va_arg with appropriate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_S(buffer *b_r, tags *t)
{
	char *hold;
	char *b_str;
	int i, j, k, l, minus, b_str_size, hold_len;
	/* get arg from va_arg and store */
	hold = va_arg(b_r->ap, char *);
	minus = i = l = 0;
	hold = _to_hex_unreadable(b_r, t, hold);
	/*check the precision tag*/
	hold_len = str_len(hold);
	/* if prec is found, ignore width */
	if (t->prec != -1 && t->prec < hold_len)
		hold_len = t->prec;
	/* if width if found */
	if (t->width > hold_len)
	{
		b_str = _str_whelp(t, hold, hold_len);
		b_str_size = t->width;
	}
	/* no width given */
	else
	{
		b_str_size = hold_len;
		b_str = malloc(b_str_size * sizeof(char));
		while (i < b_str_size)
			b_str[i] = hold[i], i++;
	}
	for (j = 0; j < b_str_size; j++)
		b_r->buf[b_r->bp++] = b_str[j];
	free(b_str);
}
/**
 * _str_whelp - sends va_arg with appropriate tags into buffer
 * @t: a pointer to the struct tags
 * @hold: string pulled from va_arg
 * @hold_len: length of hold after precision cut
 *
 * Return: Pointer to b_str
 */
char *_str_whelp(tags *t, char *hold, int hold_len)
{
	int i, b_str_size, minus, k, l;
	char *b_str;

	i = k = l = 0;
	b_str_size = t->width;
	b_str = malloc((b_str_size) * sizeof(char *));
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
			b_str[i] = hold[i], i++;
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
	return (b_str);
}
/**
 * _to_hex_unreadable - sends va_arg with appropriate tags into buffer
 * @b_r: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 * @hold: string to convert
 */
char *_to_hex_unreadable(buffer *b_r, tags *t, char *hold)
{
	char *holdconv, *hexhold;
	int i, j;

	i= j = 0;
	holdconv = malloc(1024);
	while (hold[i] != '\0')
	{
		if (hold[i] >= 32 && hold[i] <= 127)
			holdconv[j++] = hold[i];
		else
		{
			holdconv[j++] = '\\';
			holdconv[j++] = 'x';
			printf("hold[i].%d.\n", hold[i]);
			hexhold = _int_to_caphexstr(hold[i]);
			printf("hexhold.%s.\n",hexhold);
			if (hexhold[1] == '\0')
			{
				holdconv[j++] = '0';
				holdconv[j++] = hexhold[0];
			}
			else
			{
				holdconv[j++] = hexhold[0];
				holdconv[j++] = hexhold[1];
			}
		}
		i++;
	}
	return (holdconv);
}
