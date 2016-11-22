#include "holberton.h"
/**
 * _isFlagMinus - Bool check for if the stuct has a minus flag
 * @t: tags structure to check
 */
_isFlagMinus(tags *t)
{
	int i;

	for (i = 0; t->flags[i] != '\0'; i++)
		if (t->flags[i] == '-')
			return (1);
	return (0);
}
