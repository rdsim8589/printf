#include "holberton.h"
#include <stdio.h>
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
		printf("--start loop--\n");
		_copy(&b_r);
		printf("--start parse--\n");
		_parse(&b_r);
	}

	_write(&b_r);

	va_end(b_r.ap);
	return (b_r.printed);
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
	parse_table table[] = {
	{'d', 5, _found_spec}, {'i', 5, _found_spec},
	{'c', 5, _found_spec, _spec_c}, {'s', 5, _found_spec, _spec_s},
	{'u', 5, _found_spec}, {'o', 5, _found_spec},
	{'x', 5, _found_spec}, {'X', 5, _found_spec},
	{'b', 5, _found_spec}, {'S', 5, _found_spec},
	{'p', 5, _found_spec}, {'R', 5, _found_spec},
	{'r', 5, _found_spec}, {'%', 5, _found_spec, _spec_pct},
	{'h', 4, _found_length}, {'l', 4, _found_length},
	{'.', 3, _found_prec},
	{'1', 2, _found_width}, {'2', 2, _found_width},
	{'3', 2, _found_width}, {'4', 2, _found_width},
	{'5', 2, _found_width}, {'6', 2, _found_width},
	{'7', 2, _found_width}, {'8', 2, _found_width},
	{'9', 2, _found_width}, {'-', 1, _found_flag},
	{'+', 1, _found_flag}, {' ', 1, _found_flag},
	{'#', 1, _found_flag}, {'0', 1, _found_flag},
	/* We found nothing */ {'\0', -1, _found_flag, _spec_0}
	};

	if (b_r->format[b_r->fp] != '%' && b_r->format[b_r->fp] != '\0')
		write(1, "Parsed not at percent or null\n", 30);
	if (b_r->format[b_r->fp] == '%')
		b_r->fp++;

	_create_tag(b_r, &t, table);

	/* t now should be full of data.
		Need to match the spec in t to the spec function and call */
	printf("t.spec = %c\n", t.spec);
	if (t.spec == 'c')
		_spec_c(b_r, &t);
 	if (t.spec == 's')
		_spec_s(b_r, &t);
	if (t.spec == '\0')
		_spec_0(b_r, &t);
	if (t.spec == '%')
		b_r->buf[b_r->bp++] = '%';
	if (t.spec == 'p')
		_spec_p(b_r, &t);
}
/**
 * _create_tag - Initialize and parse, creating a valid tag
 * @b_r: the buffer structure
 * @t: stuct to fill in with tags
 */
void _create_tag(buffer *b_r, tags *t, parse_table *table)
{
	int i, j, currentLevel, tmp;

	/* Initialize tag to null */
	t->spec = '\0';
	t->length = '\0';
	t->prec = -1;
	t->width = -1;
	t->flags[0] = '\0', t->flags[1] = '\0', t->flags[2] = '\0';
	t->flags[3] = '\0', t->flags[4] = '\0';
	t->scan_i = 0;

	_parse_tag(b_r, t, table);
}
/**
 * _init_tag(parse_table *table, tags *t)
 * @table: Parsing table to read the '%___' from format
 * @t: tags to send to our specifier function
 */
void _parse_tag(buffer *b_r, tags *t, parse_table *table)
{
	int currentLevel, i, j, tmp; 

	tmp = currentLevel = i = j = 0;
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
			/*switch (table[i].level)
			{
			case 5:     
				_found_spec(b_r, t, table, i);
				break;
			case 4:
				_found_length(b_r, t, table, i);
				i = -1;
				break;
			case 3:
				_found_prec(b_r, t);
				i = -1;
				break;
			case 2:
				_found_width(b_r, t);
				i = -1;
				break;
			case 1:
				_found_flag(b_r, t, table, i);
				i = -1;
				break;
			}*/
		}
		i++;
	}
}





