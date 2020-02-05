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

int		ft_display_unsigned_int(unsigned int nb, t_flags *f)
{
	int len;
	int	st_len;
	int	st_total_len;
	int i;

	len = ft_width_nb_unsigned(nb) - 1;
	if (f->zero && f->width > 0 && f->point)
		f->zero = 0;
	f->precision = ((f->precision < 0) ? 0 : f->precision);
	f->precision = (f->zero && f->width > len) ? f->width - len : f->precision;
	st_len = (((f->precision > len) ? f->precision : len));
	st_len += ((nb < 0 && f->precision >= len) ? 1 : 0);
	st_total_len = ((f->width > st_len) ? f->width : st_len);
	i = -1;
	if (f->tiret == 0 && (i = -1))
		while (++i < st_total_len - st_len)
			ft_putchar_fd(((f->zero) ? '0' : ' '), 1);
	i = -1;
	while (++i < st_len - len)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(ft_unsigned_itoa(nb), 1);
	if (f->tiret == 1 && (i = -1))
		while (++i < st_total_len - st_len)
			ft_putchar_fd(' ', 1);
	return (st_total_len);
}
