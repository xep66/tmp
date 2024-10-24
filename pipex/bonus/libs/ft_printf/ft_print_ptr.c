#include "ft_printf.h"


int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n /= 16;
		len++;
	}
	return (len);
}


void	ft_print_addr(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_addr(n / 16);
		ft_print_addr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_char(n + '0');
		else if (n >= 10)
			ft_print_char((n - 10) + 'a');
	}
}


int	ft_print_ptr(unsigned long long ptr)
{
	int	count;

	count = 0;

	if (ptr == 0)
	{
		ft_print_str("(nil)");
		return (5);
	}
	count += ft_print_str("0x");
	ft_print_addr(ptr);
	count += ft_ptr_len(ptr);
	return (count);
}

/*
int ft_print_ptr(long unsigned int ptr)
{
	unsigned long addr = (unsigned long)ptr;
	char *result;
	int len;

	result = ft_xtoa(addr, 0);
	if (!result)
		return (0);
	len = ft_strlen(result);
	ft_print_str(result);
	free(result);
	return (len);
}
*/
