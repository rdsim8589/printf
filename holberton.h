#ifndef PRINTF_H
#define PRINTF_H
#include <stdlib.h>
#include <unistd.h>
/**
 * struct buffer - A buffer for our printf
 * @buf: Buffer to write characters
 * @format: The string passed to our printf
 * @bp: the current point in the buffer
 * @fp: the current point in the format
 * @size: the size of our buffer
 */
typedef struct buffer
{
	char *buf;
	const char *format;
	int bp;
	int fp;
	unsigned int size;
} buffer;
void _copy(buffer *);
#endif
