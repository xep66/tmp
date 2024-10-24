#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_len;
	size_t src_len;
	size_t result;
	size_t i;
	char *s;

	s = (char *)src;
	if (!dst || !src)
		return (0);
	i = 0;
	result = 0;
	src_len = ft_strlen(s);
	dst_len = ft_strlen(dst);
	if (dstsize > dst_len)
		result = dst_len + src_len;
	else
		result = src_len + dstsize;
	while (s[i] && (dst_len - 1) < dstsize)
	{
		dst[dst_len] = s[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (result);
}
