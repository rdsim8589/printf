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

	/* Main loop to create buffer from format string */
	while (b_r.format[b_r.fp] != '\0')
	{
		_copy(&b_r);
		/* call parse */
	}

	write(1, b_r.buf, b_r.bp);

	return (b_r.bp);
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

	if (b_r->format[b_r->fp] != '%' || b_r->format[b_r->fp] != '\0')
		write(1, "Parsed not at percent or null\n", 30);
	else if (b_r->format[b_r->fp] == '%')
		b_r->buf[b_r->bp++] = b_r->format[b_r->fp++];

	_create_tag(b_r, &t);

	/* t now should be full of data.
		Need to match the spec in t to the spec function and call */
}
/**
 * _create_tag - Initialize and parse, creating a valid tag
 * @b_r: the buffer structure
 * @t: stuct to fill in with tags
 */
void _create_tag(buffer *b_r, tags *t)
{
	int i, j, currentLevel, tmp;
	parse_table table[] = {
	{'d', 0, 5}, {'i', 0, 5}, {'c', 0, 5}, {'s', 0, 5}, {'u', 0, 5},
	{'o', 0, 5}, {'x', 0, 5}, {'X', 0, 5}, {'b', 0, 5}, {'S', 0, 5},
	{'p', 0, 5}, {'R', 0, 5}, {'r', 0, 5}, {'%', 0, 5},
	{'h', 0, 4}, {'l', 0, 4}, {'.', 0, 3},
	/*{'0', 0, 2},*/ {'1', 0, 2}, {'2', 0, 2}, {'3', 0, 2}, {'4', 0, 2},
	{'5', 0, 2}, {'6', 0, 2}, {'7', 0, 2}, {'8', 0, 2}, {'9', 0, 2},
	{'-', 0, 1}, {'+', 0, 1}, {' ', 0, 1}, {'#', 0, 1}, {'0', 0, 1},
	/* We found nothing */ {NULL, 0, -1}
	};
		/* Initialize tag to null */
	t->spec = '\0';
	t->length[0] = '\0', t->length[1] = '\0';
	t->prec = -1, t->width = -1;
	t->flags[0] = '\0', t->flags[1] = '\0', t->flags[2] = '\0';
	t->flags[3] = '\0', t->flags[4] = '\0';

	currentLevel = 0;
	while (table[i].level >= currentLevel || currentLevel < 5)
	{
		if (table[i].c == b_r->format[b_r->fp] || table[i].c == NULL)
		{
			currentLevel = table[i].level;
			/* switch based on index */
			switch(table[i].level) {
			case 5:
				t->spec = table[i].c;
				b_r->fp++, break;
			case 4:
				if (t->length[0] != '\0')
					t->length[1] = table[i].c;
				t->length[0] = table[i].c;
				b_r->fp++, break;
			case 3:
				b_r->fp++;
				tmp = t->prec = __atoi(b_r->format, b_r->fp);
				while (tmp)
					tmp /= 10, b_r->fp++;
				break;				
			case 2:
				tmp = t->width = __atoi(b_r->format, b_r->fp);
				while (tmp)
					tmp /= 10, b_r->fp++;
				break;
			case 1:
				j = 0;
				while (1)
				{
					if (t->flags[j] = '\0')
					{
						t->flags[j] = table[i].c;
						break;
					}
					j++;
				}
				b_r->fp++, break;
			}
		}
		i++;	
	}
}		
