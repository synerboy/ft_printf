/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexamaj.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:10:57 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 15:57:35 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_config_hexmaj(t_flags flags, int *tmp_p, int *tmp_w, int width)
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
		*tmp_w = flags.width - width;
	if (flags.width > flags.precision && flags.width > width
	&& flags.precision > width)
		*tmp_w = flags.width - flags.precision;
}

void	ft_show_result_hexmaj(t_flags f, int tmp_w, int tmp_p, __uint128_t r)
{
	if (f.tiret == 0 && (f.zero == 0 || f.point))
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
	if (f.zero || (f.width > 0 && f.tiret == 0) || f.tiret)
		while (tmp_p-- > 0)
			ft_putchar_fd('0', 2);
	if (f.zero && f.width > 0 && f.tiret == 0 && f.point == 0)
		while (tmp_w-- > 0)
			ft_putchar_fd('0', 2);
	ft_putpointermaj_fd(r, 2);
	if (f.tiret)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
}

void	ft_display_hexamaj(t_flags *flags, char *hex)
{
	unsigned long	read;
	int			width;
	int			tmp_w;
	int			tmp_p;

	tmp_w = 0;
	tmp_p = 0;
	read = (unsigned long)hex;
	width = ft_width_nb_64(read);
	if (flags->width < 0)
	{
		flags->tiret = 1;
		flags->width = -flags->width;
	}
	if (read)
	{
		ft_config_hexmaj(*flags, &tmp_p, &tmp_w, width);
		ft_show_result_hexmaj(*flags, tmp_w, tmp_p, read);
	}
	else
	{
		flags->point = 0;
		flags->precision = 0;
		ft_display_string("(null)", flags);
	}
}
