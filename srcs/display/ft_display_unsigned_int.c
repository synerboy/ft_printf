/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:11 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 16:08:52 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_display_unsigned_int_cfg(t_flags *f, int *width_nb, int *p, int *w)
{
	if (f->width < 0)
	{
		f->tiret = 1;
		f->width = -f->width;
	}
	if (f->width > *width_nb && f->precision == 0)
	{
		if (f->zero)
			*p = f->width - *width_nb;
		if (f->zero == 0)
			*w = f->width - *width_nb;
	}
	if (f->width <= f->precision && f->precision >= *width_nb && !(f->width))
	{
		*w = 0;
		*p = f->precision - *width_nb;
	}
	if (f->width >= f->precision && f->precision >= *width_nb)
	{
		*w = f->width - (f->precision);
		*p = f->precision - *width_nb;
	}
	if (f->width >= f->precision && f->precision <= *width_nb)
		if (f->zero == 0)
			*w = f->width - *width_nb;
}

void	ft_display_unsigned_int(unsigned int nb, t_flags *flags)
{
	int width_nb;
	int tmp_w;
	int tmp_p;

	tmp_w = 0;
	tmp_p = 0;
	flags->unsignedint_tmp = nb;
	width_nb = ft_width_nb_unsigned(flags->unsignedint_tmp) - 1;
	ft_display_unsigned_int_cfg(flags, &width_nb, &tmp_p, &tmp_w);
	if (flags->precision >= flags->width && width_nb > flags->width)
		tmp_p = flags->precision - width_nb;
	if (flags->tiret == 0)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 1);
	while (tmp_p-- > 0)
		ft_putchar_fd('0', 2);
	ft_putstr_fd(ft_unsigned_itoa(nb), 1);
	if (flags->tiret)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 1);
}
