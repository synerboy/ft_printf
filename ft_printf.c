#include "ft_printf.h"

int	ft_printf(char *st, ...)
{
	va_list args;
	char	*tmp;
	int 	i;
	i = 0;
	tmp = st;
	va_start(args, st);
	while (*st)
	{
		if (*st == '%')
		{
			ft_putstr_len_fd(tmp, st - tmp, 2);
			i += (st - tmp);
			st += ft_parsing(st, &i, args);
			tmp = st + 1;
		}
		st++;
	}
	if (tmp != st)
	{
		ft_putstr_len_fd(tmp, st - tmp, 2);
		i += (st - tmp);
	}
	va_end(args);
	return (i);
}