/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:01 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 14:34:09 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_display_int_config1(t_flags *f, int *width_nb, int *tmp_w, int *tmp_p)
{
	if (f->tmp < 0)
		f->tmp2 = 1;
	if (f->tmp == 0)
		f->precision += 1;
	*width_nb = ft_width_nb(f->tmp);
	if (f->width > *width_nb && f->precision == 0)
	{
		if (f->zero)
			*tmp_p = f->width - *width_nb;
		if (f->zero == 0)
			*tmp_w = f->width - *width_nb;
	}
	if (f->width <= f->precision && f->precision >= *width_nb)
	{
		*tmp_w = 0;
		f->width = 0;
		*tmp_p = f->precision - *width_nb;
	}
	if (f->width >= f->precision && f->precision >= *width_nb)
	{
		*tmp_w = f->width - (f->precision);
		*tmp_p = f->precision - *width_nb;
	}
}

void	ft_display_int_config2(t_flags *f, int *width_nb, int *tmp_w, int *tmp_p)
{
	if (f->width >= f->precision && f->precision <= *width_nb)
		if (f->zero == 0)
			*tmp_w = f->width - *width_nb;
	if (f->precision >= f->width && *width_nb > f->width)
		*tmp_p = f->precision - *width_nb;
	if (f->tmp2)
		*tmp_w = *tmp_w - 1;
	if (f->tmp2 && f->width > f->precision && f->precision <= *width_nb)
	{
		*tmp_p = *tmp_p - 1;
		*tmp_w = *tmp_w + 1;
	}
	if (f->precision > 0 && f->tmp == 0)
	{
		*tmp_p = f->precision - 1;
		if (f->width > 0)
			*tmp_w = *tmp_w + 1;
	}
}

void	ft_display_int_show(t_flags f, int *tmp_w, int *tmp_p)
{
	if (f.tiret == 0)
		while (*tmp_w > 0)
		{
			ft_putchar_fd(' ', 1);
			*tmp_w = *tmp_w - 1;
		}
	if (f.tmp2)
		ft_putchar_fd('-', 1);
	if (f.tmp2)
		*tmp_p = *tmp_p + 1;
	while (*tmp_p > 0)
	{
		ft_putchar_fd('0', 1);
		*tmp_p = *tmp_p - 1;
	}
}

void	ft_display_int(int nb, t_flags *flags)
{
	int width_nb;
	int tmp_w;
	int tmp_p;

	tmp_w = 0;
	tmp_p = 0;
	flags->tmp2 = 0;
	flags->tmp = nb;
	ft_display_int_config1(flags, &width_nb, &tmp_w, &tmp_p);
	ft_display_int_config2(flags, &width_nb, &tmp_w, &tmp_p);
	ft_display_int_show(*flags, &tmp_w, &tmp_p);
	if (nb != 0)
	{
		if (flags->tmp2)
			ft_putnbr_fd(nb * -1, 1);
		else
			ft_putnbr_fd(nb, 1);
	}
	if (flags->tiret)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 1);
}
