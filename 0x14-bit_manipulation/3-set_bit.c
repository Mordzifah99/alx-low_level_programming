#include "main.h"

/**
 * set_bit - sets the value of the bits to 0 at a given index
 * @index: index of the bit
 * @n: a pointer to an unsigned integer
 * @*n: dereferenced to access the value of the variable
 * Return: 0 for succesful and -1 for unsuccesful
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	*n |= (1UL << index);

	return (0);
}
