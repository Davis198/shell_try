#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @v: the pointer to the memory area
 * @b: the byte to fill *v with
 * @n: the amount of bytes to be filled
 * Return: (v) a pointer to the memory area v
 */
char *_memset(char *v, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		v[i] = b;
	return (v);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **o = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(o);
}

/**
 * _real - real locates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_real(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

