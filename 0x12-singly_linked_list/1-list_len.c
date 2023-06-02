#include <stdlib.h>
#include "lists.h"

/**
 * list_len: returns the numberof elements in a linked list
 * Return: n(size_t of h)
 */

size_t list_len(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		n++;
		h = h->next;
	}
	return (n);
}
