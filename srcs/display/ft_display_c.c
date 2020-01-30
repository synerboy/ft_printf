#include "../../ft_printf.h"

void	ft_display_c(char c, t_flags *flags)
{
	(void)c;
	(void)flags;

	int tmp_w;

	tmp_w = flags->width;
	if (tmp_w < 0)
	{
		flags->tiret = 1;
		tmp_w = -tmp_w;
	}
	if ((flags->point == 0))
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
