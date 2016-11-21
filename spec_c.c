#include "holberton.h"
#include <stdio.h>
/**
 *
 */
void _spec_c(buffer *b_r, tags *t)
{
	char hold;

	if (b_r != NULL)
	{
		/* get arg from va_arg and store */
		hold = va_arg(b_r->ap, int);
		/* determine the len of arg*/
		/* do the tag stuff*/
		/* add into buffer and advance buffer*/
		b_r->buf[b_r->bp++] = hold;
	}
}
