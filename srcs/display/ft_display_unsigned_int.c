/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_unsigned_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:11 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/07 11:54:27 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_display_unsigned_int_show(t_flags *f, int *tt, int *stlen, int *len)
{
	int i;

	i = -1;
	if (f->tiret == 0)
		while (++i < *tt - *stlen)
			ft_putchar_fd(((f->zero) ? '0' : ' '), 1);
	i = -1;
	while (++i < *stlen - *len)
		ft_putchar_fd('0', 1);
	if ((f->point && f->precision == 0) && f->unsignedint_tmp == 0)
		;
	else
		ft_putstr_fd(ft_unsigned_itoa(f->unsignedint_tmp), 1);
	i = -1;
	if (f->tiret == 1)
		while (++i < *tt - *stlen)
			ft_putchar_fd(' ', 1);
}

int		ft_display_unsigned_int(unsigned int nb, t_flags *f)
{
	int len;
	int	st_len;
	int	st_total_len;

	f->unsignedint_tmp = nb;
	len = ft_width_nb_unsigned(nb) - 1;
	len -= ((len == 1 && f->precision == 0 && f->point == 1) ? 1 : 0);
	if (f->zero && f->width > 0 && f->point)
		f->zero = 0;
	f->precision = ((f->precision < 0) ? 0 : f->precision);
	f->precision = (f->zero && f->width > len) ? f->width - len : f->precision;
	st_len = (((f->precision > len) ? f->precision : len));
	st_len += ((nb < 0 && f->precision >= len) ? 1 : 0);
	st_total_len = ((f->width > st_len) ? f->width : st_len);
	ft_display_unsigned_int_show(f, &st_total_len, &st_len, &len);
	return (st_total_len);
}
