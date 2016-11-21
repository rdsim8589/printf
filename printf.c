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
/**
 * _parse - take string from % and parse tags into correct string for buffer
 * @b_r: the buffer structure
 */
void _parse(buffer *b_r)
{
	tags t;

	if (b_r->format[b_r->fp] != '%' || b_r->format[b_r->fp] != '\0')
		write(1, "Parsed not at percent or null\n", 30);

	_create_tag(b_r, &t);

	/* t now should be full of data.
		Need to match the spec in t to the spec function and call */
}
/**
 * _create_tag - Initialize and parse, creating a valid tag
 * @b_r: the buffer structure
 * @t: stuct to fill in with tags
 */
void _create_tag(buffer *b_r, tags *t)
{
	/* Initialize tag to null */
	t->spec = '\0';
	t->length[0] = '\0', t->length[1] = '\0';
	t->prec = -1;
	t->width = -1;
	t->flags[0] = '\0', t->flags[1] = '\0', t->flags[2] = '\0';
	t->flags[3] = '\0', t->flags[4] = '\0';

	
}
