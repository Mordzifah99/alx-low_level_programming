#include "main.h"

/**
 * flip_bits -  returns the number of bits you would need to flip to get from one number to another
 * @n: first number
 * @m: second number
 * Return: number of bits flipped
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i;
    
	for (i = 0; i < sizeof(unsigned long int) * 8; i++)
	{
		count += (exclusive >> i) & 1;
	}

	return (0);
}
