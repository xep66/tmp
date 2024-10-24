#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int result;
	size_t i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	result = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			result = (const unsigned char)s1[i] - (const unsigned char)s2[i];
			return (result);
		}
		i++;
	}
	return (result);
}
