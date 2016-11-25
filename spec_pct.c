#include "holberton.h"
/**
 * _spec_pct - sends a % into buffer
 * @b_r: a pointer to the buffer
 */
void _spec_pct(buffer *b_r)
{
	/* We should only print the percent if it's not the last char found */
	if (b_r->format[b_r->fp + 1] != '\0')
		_write(b_r, '%');
}
