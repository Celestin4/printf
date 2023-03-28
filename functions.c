#include "main.h"

/**
 * print_ch - print single char at a time
 * @args: list of runtime arguments
 * @count: pointer to count of printed bytes
 * @sz: size specifier
 *
 * Return: 0
 */
int print_ch(va_list args, int *count, int sz)
{
	int x;

	UN_NEEDED(sz);
	x = va_arg(args, int);
	write(1, &x, 1);
	(*count)++;
	return (0);
}
/**
 * print_str - print a string parameter
 * @pars: the list of variable type arguments
 * @count: pointer to number of chars printed so far
 * @sz: size specifier(unneeded here)
 *
 * Return: 0
 */
int print_str(va_list pars, int *count, int sz)
{
	char *x;

	UN_NEEDED(sz);
	x = va_arg(pars, char *);
	if (x == NULL)
	{
		char *nil = "(null)";

		write(1, nil, 6);
		*count += 6;
	}
	else
	{
		while (*x != '\0')
		{
			_putchar(*x);
			(*count)++;
			x++;
		}
	}
	return (0);
}

/**
 * binconv - convert to binary
 * @args: list of runtime arguments
 * @count: pointer to number of bytes computed in the
 *	calling function
 * @sz: size specifier, unneeded here
 *
 *Return: 0
 */
int binconv(va_list args, int *count, int sz)
{
	int i, x;
	char bits[100];

	UN_NEEDED(sz);
	i = 0;
	x = va_arg(args, int);
	while (x > 0)
	{
		bits[i++] = x % 2 + '0';
		x /= 2;
	}
	for (i -= 1; i >= 0; i--)
	{
		printer(bits, i);
		(*count)++;
	}
	return (0);
}
/**
 * print_percent - print a percent sign
 * @list: a list of runtime arguments
 * @count: pointer to number of chars printed
 * @sz: the size specifier
 *
 * Return: 0
 */
int print_percent(va_list list, int *count, int sz)
{
	char x;

	UN_NEEDED(sz);
	UN_NEEDED(list);
	x = '%';
	_putchar(x);
	(*count)++;
	return (0);
}

/**
 * print_mem - print memory address
 * @list: list of runtime arguments
 * @count: address of memory containing number of
 * printed bytes so far
 * @sz: the size specifier
 *
 * Return: 0
 */
int print_mem(va_list list, int *count, int sz)
{
	char address[BUFF];
	unsigned long int x, mod, i;
	char hex[] = "0123456789abcdef";

	UN_NEEDED(sz);
	x = va_arg(list, unsigned long int);
	if (!x)
	{
		char *null = "(nil)";

		write(1, null, 5);
		*count += 5;
	}
	else
	{
		_putchar('0');
		_putchar('x');
		*count += 2;
		for (i = 0; x > 0; x /= 16)
		{
			mod = x % 16;
			address[i++] = hex[mod];
		}
		for (i -= 1;; i--)
		{
			_putchar(address[i]);
			(*count)++;
			if (address + i == address)
				break;
		}
	}
	return (0);
}
