#include "../../ft_printf.h"

void	ft_display_percent(t_flags *flags)
{
	int tmp_w;

	tmp_w = flags->width;
	if (tmp_w < 0)
	{
		flags->tiret = 1;
		tmp_w = -tmp_w;
	}
	if (flags->tiret == 0)
		while (tmp_w-- > 1)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd('%', 1);
	if (flags->tiret)
		while (tmp_w-- > 1)
			ft_putchar_fd(' ', 1);
}