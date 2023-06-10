#include "main.h"

/**
 * get_bit - a function that returns the value of a bit at a given index
 * index is the index, starting from zero of the bits i want to get
 * @index: the index of the bit
 * @n: unsigned long int number
 * bit_value: representing the value of a bit at a given index
 *
 * Return:the value of the bit at index or -1 if an error occurs
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_value;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	bit_value = (n >> index) & 1;

	return (bit_value);
}
