#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
	if (fd < 0)
		return;

	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}
