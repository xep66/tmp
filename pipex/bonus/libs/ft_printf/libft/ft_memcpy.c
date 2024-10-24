#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dst_ptr;
	const char *src_ptr;

	dst_ptr = dst;
	src_ptr = src;
	while (n--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}
