#include "ft_printf.h"

int ft_print_str(char *s)
{
	char *ptr;
	int len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	ptr = (char *)s;
	if (!ptr)
		return (0);
	while (*ptr != '\0')
	{
		write(1, ptr, 1);
		ptr++;
	}
	return (len);
}
