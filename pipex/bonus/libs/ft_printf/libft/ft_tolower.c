#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 65 && c < 91)
		return (c += 32);
	return (0);
}
