#include <stdio.h>
#include "lists.h"

/**
 * function that prints all the elements of a list
 * @h: pointer to the list to print
 * Return:s(size_t)
 */

size_t print_list(const list_t *h)
{
 size_t s = 0;

 while (h)
 {
 if (!h->str)
 printf("[0] (nil)\n");
 else
 printf("[%u] %s\n", h->len, h->str);
 h = h->next;
 s++;
 }

 return (s);
}
