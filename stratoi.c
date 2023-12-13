#include "shell.h"

/**
 * modsys - a func that returns 1 for interactive mode of shell
 * @d_typeinfo: &ofstruct
 *
 * Return: 1 if shell is interactive(sysallowmdfctn) 0 for else
 */
int modsys(d_type *d_typeinfo)
{
	return (isatty(STDIN_FILENO) && d_typeinfo->rdfiledes <= 2);
}

/**
 * delimchar - it identify delimiter character inside a string
 * @s: checked char whether or not is delimiter
 * @delimiter: delimiter char taken as string
 * Return: if true, comp returns 1, and 0 for false
 */
int delimchar(char s, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == s)
			return (1);
	return (0);
}

/**
 *alphachar - a func isalpha to check for alphabetic character
 *@s: denotes input character
 *Return: 0 if char not alphabet, 1 if alphabet char is found
 */

int alphachar(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *strtint - a func that converts a string to an integer
 *@s: the parameter string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int strtint(char *s)
{
	int k, symbol = 1, id = 0, prnt;
	unsigned int product = 0;

	for (k = 0;  s[k] != '\0' && id != 2; k++)
	{
		if (s[k] == '-')
			symbol *= -1;

		if (s[k] >= '0' && s[k] <= '9')
		{
			id = 1;
			product *= 10;
			product += (s[k] - '0');
		}
		else if (id == 1)
			id = 2;
	}

	if (symbol == -1)
		prnt = -product;
	else
		prnt = product;

	return (prnt);
}
