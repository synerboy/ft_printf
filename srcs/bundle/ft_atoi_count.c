#include "../../ft_printf.h"

int	ft_atoi_count(const char *str, int *o)
{
	int i;
	int neg;
	int nb;

	nb = 0;
	neg = 0;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\f' ||
	str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i++] - 48;
		(*o)++;
	}
	if (neg)
		return (-nb);
	return (nb);
}