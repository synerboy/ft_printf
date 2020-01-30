#include "../../ft_printf.h"

void	ft_display_c(char c, t_flags *flags)
{
	(void)c;
	(void)flags;

	int tmp_w;

	if (flags->width < 0)
	{
		flags->tiret = 1;
		flags->width = -flags->width;
	}
	tmp_w = flags->width;
	if ((flags->precision == 0) && flags->percent == 1)
	{
		if (flags->tiret == 0)
			while (tmp_w-- > 1)
				ft_putchar_fd(' ', 2);
		ft_putchar_fd(c, 2);
		if (flags->tiret)
			while (tmp_w-- > 1)
				ft_putchar_fd(' ', 2);
	}
	else
		ft_putchar_fd(c, 2);
}
