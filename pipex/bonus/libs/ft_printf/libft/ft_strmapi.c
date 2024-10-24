#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char *result;
	size_t i;

	i = 0;

	if (!s || !f)
		return (NULL);
	result = malloc(sizeof(char *));
	if (!result)
		return (NULL);

	while (i < ft_strlen(s))
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
