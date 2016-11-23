#include "holberton.h"
/**
 *
 */

void _spec_num_help(buffer *b_r, tags *t, char *num_str, int minus)
{
	int i, j, k, l, s_len, perc;
	char* tmp_str;
	char front[] = "\0\0";

	tmp_str = num_str;
	s_len = str_len(num_str);
	perc = t->perc;
	l = j = 0;
	if (t->prec != -1)
	{
		/*if prec found, set 0_flag to /0*/
		/*might not need to 0_flag to /0. Applying padding to num_str should account for this*/
		for (i = 0; i < 4; i++)
		{
			if (t->flags[i] == '0')
				t->flags[i] == '\0';
		}
		/*adding zero if prec found*/
		if (perc > s_len)
		{
			tmp_str = malloc(perc * sizeof(char));
			while (j < (perc - s_len))
			{
				tmp_str[j] = 0;
				j++;
			}
			while (j < perc)
			{
				tmp_str[j] = num_str[l];
				j++;
				l++;
			}
		}
	}
	/*adding signs depending on spec*/
	if (t->spec = 'd' || t->spec = 'i')
	{
		if (minus == 1)
			front[1] = '-';
		else if (_isFlagPlus(t) == 1)
			front[1] = '+';
		else if (_isFlagSpace(t) == 1)
			front[1] = ' ';
	}
	else if ((t->spec = 'o' || t->spec = 'X' || t->spec = 'x') &&
		 _isFlagHashtag(t) == 1)
	{
		front[0] = '0';
		if (t->spec = 'X')
			front[1] = 'X';
		else if (t->spec = 'x')
			front[1] = 'x';
	}
	/*applying padding to num_str*/
	if ((str_len(front) + str_len(tmp_str)) < t->width)
	{
		buf_str = malloc(t->width * sizeof(char));
		k = i = 0;
		if (_isFlagZero(t) == 1 && _isFlagMinus(t) == 1)
		{
			/*add front[] + '0' + tmp_str*/
			/* add of front*/
			while (front[k] != '\0')
			{
				buf_str[k] = front[k];
				k++;
			}
			/*add width - len(front) - len(tmp_str) amount of 0*/
			while (k < (t->width - str_len(tmp_str) - str_len(front)))
			{
				buf_str[k] = '0';
				k++;
			}
			while (k < t->width)
			{
				buf_str[k] = tmp_str[i];
				k++;
				i++;
			}
		}
		else if (_isFlagMinus == 1)
		{
			/*add front[] + tmp_str + "(space)"*/
			/* add the front*/
			while (front[k] != '\0')
			{
				buf_str[k] = front[k];
				k++;
			}
			/*add tmp_str and starting with the index at str_len(front)*/
			while (k < str_len(tmp_str) + str_len(front))
			{
				buf_str[k] = tmp_str[i];
				k++;
				i++;
			}
			while (k < t->width)
			{
				buf_str[k] = ' ';
				k++;
			}
		}
		else if (_isFlagMinus == 0)
		{
			/*add "(space)" + front[] + tmp_str*/
			/*add width - len(front) - len(tmp_str) amount of  */
			while (k < (t->width - str_len(tmp_str) - str_len(front)))
			{
				buf_str[k] = ' ';
				k++;
			}
			/*add the front*/
			while (front[k] != '\0')
			{
				buf_str[k] = front[k];
				k++;
			}
			/*add the remiaing space with width*/
			while (k < t->width)
			{
				buf_str[k] = ' ';
				k++;
			}
		}
		else
		{
			printf("ERROR: not all tags caught by applying padding to num_str");
		}
	}
	/*if width is less than len(tmp_str) + len(front)*/
	else
	{
		
	}
	for (j = 0; j < b_str_size; j++)
		b_r->buf[b_r->bp++] = b_str[j];
	free(b_str);

}
