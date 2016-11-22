#include "holberton.h"
/**
 * spec_0 - sends t.scanned into buffer
 * @b_r: a pointer to the buffer
 */
void _spec_0(buffer *b_r, tags *t)
{
	int i;

	for (i = 0; i < t->scan_i; i++)
		b_r->buf[b_r->bp++] = t->scanned[i];
}
