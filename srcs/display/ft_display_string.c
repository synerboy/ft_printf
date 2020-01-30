#include "../../ft_printf.h"

void	ft_display_string(char *c, t_flags *flags)
{
	(void)c;
	(void)flags;
	int len;
	int tmp_w;
	int tmp_len;

	len = ft_strlen(c);
	tmp_len = len;
	tmp_w = flags->width;
	if (flags->precision < len)
		tmp_len = flags->precision;
	if (flags->width >= flags->precision && flags->width > len)
	{
		tmp_w = flags->width - len;
		tmp_len = len;
	}
	if (flags->width >= flags->precision && flags->precision < len)
	{
		tmp_len = flags->precision;
		tmp_w = flags->width - tmp_len;
	}
	if (flags->width < flags->precision && flags->width < len)
		tmp_w = 0;
	if (flags->width <= flags->precision && flags->width > len)
		tmp_w = flags->width - len;
	if (flags->width && flags->point == 0 && flags->width < len)
	{
		tmp_w = 0;
		tmp_len = len;
	}
	if (flags->width >= len)
	{
		tmp_len = len;
		if (flags->precision < len)
			tmp_len =flags->precision;
		tmp_w = flags->width - tmp_len;
	}
	if (flags->tiret == 0)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
	ft_putstr_len_fd(c, tmp_len, 2);
	if (flags->tiret)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
		
}
