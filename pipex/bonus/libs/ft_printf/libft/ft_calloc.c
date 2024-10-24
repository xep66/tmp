#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
	void    *ptr;

	if (size == 0 || count == 0)
		return (malloc(0));
	if (count > ((SIZE_MAX) / size))
		return (NULL);
	ptr = malloc(sizeof(count * size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
