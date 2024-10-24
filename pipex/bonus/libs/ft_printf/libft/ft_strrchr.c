#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	const char *last;
	char c_char;

	c_char = (char)c;
	last = NULL;
	while (*s)
	{
		if (*s == c_char)
			last = s;
		s++;
	}

	if (c_char == '\0')
		return ((char *)s);
	return ((char *)last);
}
