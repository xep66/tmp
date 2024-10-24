#include "libft.h"

size_t	ft_itoa_len(int c)
{
	size_t	len;

	len = 0;
	if (c < 0)
		len++;
	while (c)
	{
		c /= 10;
		len++;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char	*ft_itoa(int n)
{
	int	sign;
	size_t	len;
	char	*str;

	len = ft_itoa_len(n);
	str = malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	sign = 0;
	if (n < 0)
		sign = 1;
	n = ft_abs(n);
	*(str + len) = '\0';
	while (len--)
	{
		*(str + len) = '0' + (n % 10);
		n /= 10;
	}
	if (sign)
		*(str) = '-';
	return (str);
}
