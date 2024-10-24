#include "libft.h"

int ft_atoi(const char *str)
{
	int nbr;
	int sign;
	int i;

	sign = 1;
	nbr = 0;
	i = 0;

	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r')
		i++;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 0 && str[i] <= 9)
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	nbr *= sign;
	return (nbr);
}
