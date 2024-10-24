#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char *dst_ptr;
	const char *src_ptr;

	if (!dst || !src)
		return (NULL);
	dst_ptr = dst;
	src_ptr = src;
	while (n--)
		dst_ptr[n] = src_ptr[n];
	return (dst);
}
