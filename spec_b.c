#include "holberton.h"
/**
* _spec_b - sends va-arg with appropriat tags into buffer
* @b_r: a pointer to the struct buffer
* @t: a pointer to the struct tags
*/
void _spec_b(buffer *b_r, tags *t)
{
	int n_hold;
	char *num_str;

	n_hold = va_arg(b_r->ap, int);


	num_str = malloc(1024);
	num_str = _uint_to_binstr(n_hold);
	_spec_num_help(b_r, t, num_str, 0);
	free(num_str);
}
/**
* _spec_o - sends va-arg with appropriat tags into buffer
* @b_r: a pointer to the struct buffer
* @t: a pointer to the struct tags
*/
void _spec_o(buffer *b_r, tags *t)
{
	int n_hold;
	char *num_str;

	n_hold = va_arg(b_r->ap, int);


	num_str = malloc(1024);
	num_str = _int_to_octstr(n_hold);
	_spec_num_help(b_r, t, num_str, 0);
	free(num_str);
}
