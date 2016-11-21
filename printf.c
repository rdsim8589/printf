#include "holberton.h"
/**
 * _printf - Recreate stdio's printf
 * @format: Formatted string to print to stdout
 *
 * Return: Number of chars printed
 */
int _printf(const char *format, ...)
{
	/* Create buffer structure b_r and initalize */
	buffer b_r;

	b_r.format = format;
	b_r.fp = 0;
	b_r.bp = 0;
	b_r.size = 1024;
	b_r.buf = malloc(b_r.size);

	/* Main loop to create buffer from format string */
	while (b_r.format[b_r.fp] != '\0')
	{
		_copy(&b_r);
		/* call parse */
	}

	write(1, b_r.buf, b_r.bp);

	return (b_r.bp);
}
/**
 * _copy - directly copy from format to buffer
 * @b_r: the buffer structure
 */
void _copy(buffer *b_r)
{
	while (b_r->format[b_r->fp] != '%' && b_r->format[b_r->fp] != '\0')
		b_r->buf[b_r->bp++] = b_r->format[b_r->fp++];
}
