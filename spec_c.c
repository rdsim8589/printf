#include "holberton.h"
#include <stdio.h>
/**
 *
 */
void _spec_c(buffer *b_r, tags *t)
{
	char hold;

	printf("Hi, I made it into char spec\n");
	printf("The current buffer point is %d, and the current buffer is %s\n", b_r->bp, b_r->buf);
	printf("The current format point is %d\n", b_r->fp);
	if (b_r != NULL)
	{
/* get arg from va_arg and store */
		hold = va_arg(b_r->ap, int);
		printf("hold = %c\n", hold);
/* determine the len of arg*/
/* do the tag stuff*/
/* add into buffer and advance buffer*/
		b_r->buf[b_r->bp++] = hold;
	}
}
