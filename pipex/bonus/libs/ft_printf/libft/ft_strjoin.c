#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	size_t size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str + ft_strlen(s1), s2, size);
	return (str);
}
