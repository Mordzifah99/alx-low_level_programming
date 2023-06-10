#include "main.h"

/**
 * print_binary - function that prints the binary representation of a number
 * @n: numbers to print in binary
 * Return: the converted number
 */
void print_binary(unsigned long int n)
{
	int j, count = 0;
	unsigned long int fresh;

	for (j = sizeof(unsigned long int) * 8 - 1; j >= 0; j--)
	{
		fresh = n >> j;
		if (fresh & 1)
		{
			_putchar('1');
			count++;
		} else if (count)
		{
			_putchar('0');
		}
	}

		if (!count)
		{
			_putchar('0');
		}
}
