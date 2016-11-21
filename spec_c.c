#include "holberton.h"
/**
 *
 */
void _spec_c(*b_r, *t)
{
	char hold;

	if (b_r != NULL)
	{
/* get arg from va_arg and store */
		hold = va_arg(b_r->ap, char);
/* determine the len of arg*/
/* do the tag stuff*/
/* add into buffer and advance buffer*/
		b_r->buf[bp++] = hold;
	}
}
