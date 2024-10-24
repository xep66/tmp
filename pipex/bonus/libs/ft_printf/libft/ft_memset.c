#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char *ptr;

	ptr = dst;
	while (len--)
		*ptr++ = (unsigned char)c;
	return (dst);
}
