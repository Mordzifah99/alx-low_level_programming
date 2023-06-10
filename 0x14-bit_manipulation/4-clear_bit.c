#include "main.h"

/**
 * clear_bit - sets the bit of a vlue to 0
 * @n: pointer to a number
 * @index: index of the bits
 * Return: 1 for successful and -1 for unsuccessful
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int y;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	y = ~(1UL << index);
	*n &= y;

	return (0);
}
