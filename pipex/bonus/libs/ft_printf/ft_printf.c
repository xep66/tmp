#include "ft_printf.h"

int	ft_format(va_list args, const char f)
{
	int ret_len;

	ret_len = 0;
	if (f == 'c')
		ret_len += ft_print_char(va_arg(args, int));
	else if (f == 's')
		ret_len += ft_print_str(va_arg(args, char *));
	else if (f == 'p')
		ret_len += ft_print_ptr((unsigned long long)va_arg(args, void *));
	else if (f == 'd' || f == 'i')
		ret_len += ft_print_int(va_arg(args, int));
	else if (f == 'u')
		ret_len += ft_print_unsigned(va_arg(args, int));
	else if (f == 'x' || f == 'X')
		ret_len += ft_print_hex(va_arg(args, unsigned int), f);
	else if (f == '%')
	{
		ft_print_pct();
		ret_len++;
	}
	return (ret_len);
}
int ft_printf(const char *f, ...)
{
	va_list args;
	int print_len;
	int i;

	i = 0;
	print_len = 0;
	va_start(args, f);
	while (f[i] != '\0')
	{
		if (f[i] == '%')
		{
			print_len += ft_format(args, f[i + 1]);
			i++;
		}
		else
			print_len += ft_print_char(f[i]);
		i++;
	}
	va_end(args);
	return (print_len);
}
/*
gcc ft_print_char.c ft_print_hex.c ft_print_int.c ft_print_unsigned.c ft_print_ptr.c ft_print_pct.c ft_print_str.c ft_printf.c
*/
