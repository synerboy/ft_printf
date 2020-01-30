#include "../../ft_printf.h"

int	ft_width_nb_64(__uint64_t n)
{
	__uint64_t ct;

	ct = 0;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 16;
		ct++;
	}
	return (ct);
}

int	ft_width_nb(int n)
{
	int ct;
	int neg;

	ct = 0;
	neg = 0;
	if (n < 0)
		neg = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 10;
		ct++;
	}
	return (ct + neg);
}

int	ft_width_nb_unsigned(unsigned int n)
{
	int ct;

	ct = 0;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 10;
		ct++;
	}
	return (ct + 1);
}