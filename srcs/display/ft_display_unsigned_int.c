#include "../../ft_printf.h"

void	ft_display_unsigned_int(unsigned int nb, t_flags *flags)
{
	(void)flags;
	int width_nb;
	int tmp_w = 0;
	int tmp_p = 0;

	width_nb = ft_width_nb_unsigned(nb) - 1;
	if (flags->width > width_nb && flags->precision == 0)
	{
		if (flags->zero)
			tmp_p = flags->width - width_nb;
		if (flags->zero == 0)
			tmp_w = flags->width - width_nb;
	}
	if (flags->width <= flags->precision 
	&& flags->precision >= width_nb)
	{
		tmp_w = flags->width = 0;
		tmp_p = flags->precision - width_nb;
	}
	if (flags->width >= flags->precision &&
	flags->precision >= width_nb)
	{
		tmp_w = flags->width - (flags->precision);
		tmp_p = flags->precision - width_nb;
	}
	if (flags->width >= flags->precision &&
	flags->precision <= width_nb)
	{
		if (flags->zero == 0)
			tmp_w = flags->width - width_nb;
	}
	if (flags->precision >= flags->width 
	&& width_nb > flags->width)
		tmp_p = flags->precision - width_nb;
	if (flags->tiret == 0)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
	while (tmp_p-- > 0)
		ft_putchar_fd('0', 2);
	ft_putstr_fd(ft_unsigned_itoa(nb), 2);
	if (flags->tiret)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
}