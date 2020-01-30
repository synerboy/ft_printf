#include "../../ft_printf.h"

// 

void	ft_display_int(int nb, t_flags *flags)
{
	(void)flags;
	int width_nb;
	int tmp_w = 0;
	int tmp_p = 0;
	int neg = 0;

	if (nb < 0)
		neg = 1;
	if (nb == 0)
		flags->precision += 1;
	width_nb = ft_width_nb(nb);
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
	{
		tmp_p = flags->precision - width_nb;
	}
	if (neg)
		tmp_w--;
	if (neg && flags->width > flags->precision &&
	flags->precision <= width_nb)
	{
		tmp_p--;
		tmp_w++;
	}
	if (flags->precision > 0 && nb == 0)
	{
		tmp_p = flags->precision - 1;
		if (flags->width > 0)
			tmp_w++;
	}
	if (flags->tiret == 0)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
	if (neg)
		ft_putchar_fd('-', 2);
	if (neg)
		tmp_p++;
	while (tmp_p-- > 0)
		ft_putchar_fd('0', 2);
	if (nb != 0)
	{
		if (neg)
			ft_putnbr_fd(nb * -1, 2);
		else
			ft_putnbr_fd(nb, 2);
	}
	if (flags->tiret)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
}