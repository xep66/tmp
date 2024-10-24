#include "ft_printf.h"

size_t ft_xtoa_len(unsigned int n)
{
	size_t len;

	len = 0;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char *ft_hex_to_string(unsigned long int n, size_t len)
{
	int		mod;
	char		*str;

	str = malloc(sizeof(char *) * (len + 1));
	if (!str)
		return (NULL);
	*(str + len) = '\0';

//	if (n == 0)
//	{
//		str[len] = '0';
//		len--;
//	}
	while (len--)
	{
		mod = n % 16;
		if (mod < 10)
			*(str + len) = mod + '0';
		else
			*(str + len) = (mod - 10) + 'a';
		n /= 16;
	}
	return (str);
}
char *ft_xtoa(unsigned long n, int is_upper)
{
	size_t len;
	char *str;
	int i;

	len = ft_xtoa_len(n);
	str = ft_hex_to_string(n, len);
	if (!str)
		return (NULL);
	if (is_upper == 1)
	{
		i = 0;
		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'f')
				str[i] -= 32;
			i++;
		}
	}
	return (str);
}

int ft_print_hex(unsigned int n, int is_upper)
{
	char 	*result;
	int 	len;
	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	if (is_upper == 'X')
		result = ft_xtoa(n, 1);
	else if (is_upper == 'x')
		result = ft_xtoa(n, 0);
	len = ft_strlen(result);
	ft_print_str(result);
	free(result);
	return (len);
}
