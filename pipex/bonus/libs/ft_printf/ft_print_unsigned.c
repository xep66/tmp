#include "ft_printf.h"

size_t ft_utoa_len(unsigned int c)
{
	size_t len;

	len = 0;
	while (c)
	{
		c /= 10;
		len++;
	}
	return (len);
}

char *ft_utoa(unsigned int n)
{
	size_t len;
	char *result;

	len = ft_utoa_len(n);

	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);

	*(result + len) = '\0';
	while (len--)
	{
		*(result + len) = '0' +  (n % 10);
		n /= 10;
	}
	return (result);
}

int ft_print_unsigned(int n)
{
	char *result;
	size_t	len;
	
	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	result = ft_utoa(n);
	len = ft_strlen(result);
	ft_print_str(result);
	free(result);
	return (len);
}
