/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:03 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/02 16:12:18 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_config_pointer(t_flags flags, int *tmp_p, int *tmp_w, int width)
{
	if (flags.width <= flags.precision && flags.precision > width)
		*tmp_p = flags.precision - width;
	if (flags.width >= flags.precision && flags.precision > width)
	{
		*tmp_w = flags.width - flags.precision - 2;
		*tmp_p = flags.precision - width;
	}
	if ((flags.width && flags.precision == 0) ||
	(flags.width >= flags.precision))
		*tmp_w = flags.width - width - 2;
	if (flags.width > flags.precision && flags.width > width
	&& flags.precision > width)
		*tmp_w = flags.width - flags.precision;
}

void	ft_show_result_pointer(t_flags f, int p, int w, unsigned long *h)
{
	char *forfree;

	if (f.tiret == 0 && (f.zero == 0 || f.point))
		while (w-- > 0)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 2);
	if (f.zero || (f.width > 0 && f.tiret == 0) || f.tiret)
		while (p-- > 0)
			ft_putchar_fd('0', 1);
	if (f.zero && f.width > 0 && f.tiret == 0 && f.point == 0)
		while (w-- > 0)
			ft_putchar_fd('0', 1);
	forfree = ft_itoa_base((long long)(*h), 16);
	ft_putstr_fd(forfree, 1);
	free(forfree);
	if (f.tiret)
		while (w-- > 0)
			ft_putchar_fd(' ', 1);
}

void	ft_show_result_null(t_flags *flags)
{
	printf("f");
	flags->point = 0;
	flags->precision = 0;
	ft_display_string("0x0", flags);
}

void	ft_display_pointer(t_flags *flags, char *pt)
{
	unsigned long	tmp;
	int				width;
	int				tmp_w;
	int				tmp_p;

	tmp_w = 0;
	tmp_p = 0;
	tmp = (unsigned long)pt;
	width = ft_width_nb_long(tmp);
	if (flags->width < 0)
	{
		flags->tiret = 1;
		flags->width = -flags->width;
	}
	if (pt)
	{
		ft_config_pointer(*flags, &tmp_p, &tmp_w, width);
		ft_show_result_pointer(*flags, tmp_p, tmp_w, &tmp);
	}
	else
		ft_show_result_null(flags);
}
