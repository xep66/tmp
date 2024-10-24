#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *s2;
	char *ptr;

	if (!s1)
		return (NULL);
	s2 = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);

	ptr = s2;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (s2);
}
