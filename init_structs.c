#include "holberton.h"
/**
 * _init_tag - Initialize tag for parsing
 * @b_r: the buffer structure
 * @t: tags stuct to fill in with tags
 */
void _init_tag(buffer *b_r, tags *t)
{
	/* Initialize tag */
	t->spec = '\0';
	t->length = '\0';
	t->prec = -1;
	t->width = -1;
	t->flags[0] = '\0', t->flags[1] = '\0', t->flags[2] = '\0';
	t->flags[3] = '\0', t->flags[4] = '\0'; t->flags[5] = '\0';
	if (b_r->format[b_r->fp] == '%')
	{
		b_r->fp++;
		t->scan_i = 1;
		t->scanned[0] = '%';
	}
}
/**
 * _init_buffer - Initialize the buffer structure
 * @b_r: copy of the buffer address
 * @format: copy of the format we will be parsing into buffer
 */
void _init_buffer(buffer *b_r, const char *format)
{
	b_r->format = format;
	b_r->buf = malloc(1024);
	b_r->tmpbuf = malloc(512);
	b_r->fp = 0;
	b_r->bp = 0;
	b_r->tp = 0;
	b_r->printed = 0;
}
