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
	b_r.printed = 0;
	va_start(b_r.ap, format);

	/* Main loop to create buffer from format string */
	while (b_r.format[b_r.fp] != '\0')
	{
		_copy(&b_r);
		_parse(&b_r);
	}

	write(1, b_r.buf, b_r.bp);
	b_r.printed += b_r.bp;

	va_end(b_r.ap);
	free(b_r.buf);
	return (b_r.printed);
}
/**
 * _copy - directly copy from format to buffer
 * @b_r: the buffer structure
 */
void _copy(buffer *b_r)
{
	while (b_r->format[b_r->fp] != '%' && b_r->format[b_r->fp] != '\0')
		_write(b_r, b_r->format[b_r->fp++]);
}
/**
 * _parse - take string from % and parse tags into correct string for buffer
 * @b_r: the buffer structure
 */
void _parse(buffer *b_r)
{
	int i;
	tags t;
	parse_table table[] = {
	{'d', 5, _found_spec, _spec_i_d}, {'i', 5, _found_spec, _spec_i_d},
	{'c', 5, _found_spec, _spec_c}, {'s', 5, _found_spec, _spec_s},
	{'u', 5, _found_spec, _spec_u}, {'o', 5, _found_spec, _spec_o},
	{'x', 5, _found_spec, _spec_x}, {'X', 5, _found_spec, _spec_X},
	{'b', 5, _found_spec, _spec_b}, {'S', 5, _found_spec, _spec_S},
	{'p', 5, _found_spec, _spec_p}, {'R', 5, _found_spec, _spec_R},
	{'r', 5, _found_spec, _spec_r}, {'%', 5, _found_spec, _spec_pct},
	{'h', 4, _found_length, _broken}, {'l', 4, _found_length, _broken},
	{'.', 3, _found_prec, _broken},
	{'1', 2, _found_width, _broken}, {'2', 2, _found_width, _broken},
	{'3', 2, _found_width, _broken}, {'4', 2, _found_width, _broken},
	{'5', 2, _found_width, _broken}, {'6', 2, _found_width, _broken},
	{'7', 2, _found_width, _broken}, {'8', 2, _found_width, _broken},
	{'9', 2, _found_width, _broken}, {'-', 1, _found_flag, _broken},
	{'+', 1, _found_flag, _broken}, {' ', 1, _found_flag, _broken},
	{'#', 1, _found_flag, _broken}, {'0', 1, _found_flag, _broken},
	/* We found nothing */ {'\0', -1, _found_flag, _spec_0}
	};

	if (b_r->format[b_r->fp] == '%')
		b_r->fp++;
	_create_tag(b_r, &t, table);

	i = 0;
	while (table[i].level > 4)
	{
		if (t.spec == table[i].c)
			table[i].specf(b_r, &t);
		i++;
	}
	if (t.spec == '\0')
		_spec_0(b_r, &t);
}
/**
 * _create_tag - Initialize and parse, creating a valid tag
 * @b_r: the buffer structure
 * @t: stuct to fill in with tags
 * @table: The parsing lookup table
 */
void _create_tag(buffer *b_r, tags *t, parse_table *table)
{
	/* Initialize tag to null */
	t->spec = '\0';
	t->length = '\0';
	t->prec = -1;
	t->width = -1;
	t->flags[0] = '\0', t->flags[1] = '\0', t->flags[2] = '\0';
	t->flags[3] = '\0', t->flags[4] = '\0';
	t->scan_i = 1;
	t->scanned[0] = '%';

	_parse_tag(b_r, t, table);
}
/**
 * _parse_tag - Build out the tags struct with tags found
 * @b_r: the buffer structure
 * @table: Parsing table to read the '%___' from format
 * @t: tags to send to our specifier function
 */
void _parse_tag(buffer *b_r, tags *t, parse_table *table)
{
	int currentLevel, i, j;

	currentLevel = i = j = 0;
	while (table[i].level >= currentLevel && currentLevel < 5)
	{
		if (table[i].c == b_r->format[b_r->fp] || table[i].c == '\0')
		{
			currentLevel = table[i].level;
			if (table[i].level == 2)
				table[i].tf(b_r, t);
			else
				table[i].tf(b_r, t, table, i);
			i = -1;
		}
		i++;
	}
}
