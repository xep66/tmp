#include "ft_printf.h"

int	ft_print_int(int n)
{
	char 	*result;
	int	len;

	if (n == INT_MAX)
	{
		ft_print_str("2147483647");
		return (10);
	}
	else if (n == INT_MIN)
	{
		ft_print_str("-2147483648");
		return (11);
	}
	if (n == 0)
	{
		ft_print_char('0');
		return (1);
	}
	result = ft_itoa(n);
	if (!result)
	{
		ft_print_str("(null)");
		return (6);
	}
	len = ft_strlen(result);
	ft_print_str(result);
	free(result);
	return (len);
}
