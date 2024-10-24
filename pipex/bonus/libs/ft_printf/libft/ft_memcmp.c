#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*s1_ptr;
	const char	*s2_ptr;
	int			result;

	result = 0;
	s1_ptr = s1;
	s2_ptr = s2;
	while (n--)
	{
		if (s1_ptr[n] != s2_ptr[n])
		{
			result = s1_ptr[n] - s2_ptr[n];
			return (result);
		}
	}
	return (result);
}
