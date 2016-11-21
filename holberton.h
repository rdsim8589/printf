#ifndef PRINTF_H
#define PRINTF_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
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
	va_list ap;
	int bp;
	int fp;
	unsigned int size;
	unsigned int printed;
} buffer;
/**
 * struct tags - Format tags after %
 * @spec: the specifier
 * @length: the length
 * @prec: the precision
 * @width: the width
 * @flags: the flags
 */
typedef struct tags
{
	char spec;
	char length[2];
	int prec;
	int width;
	char flags[4];
} tags;
/**
 * struct parse_table - Table used for parsing the %s
 * @c: character found
 * @number: number for width and precision
 * @level: which level from 5 (specification) to 1 (flags)
 */
typedef struct parse_table
{
	char c;
	int number;
	int level;
} parse_table;
void _copy(buffer *);
int _printf(const char *format, ...);
void _parse(buffer *b_r);
void _create_tag(buffer *b_r, tags *t);
int __atoi(const char *s, int n);
void _write(buffer *b_r);
void _parse_tag(parse_table *table, tags *t, buffer *b_r);
#endif
