#include "holberton.h"
/**
 * __atoi - take string, and find number the starts at point n
 * @s: string to read
 * @n: position to begin reading number
 *
 * Return: Number parsed
 */
int __atoi(const char *s, int n)
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
/**
 * _write - write the buffer and add to the printed char count, and reset.
 * @b_r: buffer to write
 */
void _write(buffer *b_r)
{
      write(1, b_r->buf, b_r->bp);
      b_r->printed += b_r->bp;
      b_r->bp = 0;
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
	while (str[i] != '\0')
		i++;
	return (i);
}
