/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:01 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/02 15:01:25 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_display_int(int nb, t_flags *f)
{
	int len;
	int	st_len;
	int	st_total_len;
	int i;

	len = ft_width_nb((nb < 0) ? -nb : nb) + ((nb < 0) ? 1 : 0);
	if (f->zero && f->width > 0 && f->point)
		f->zero = 0;
	f->precision = ((f->precision < 0) ? 0 : f->precision);
	f->precision = (f->zero && f->width > len) ? f->width - len : f->precision;
	st_len = (((f->precision > len) ? f->precision : len));
	st_len += ((nb < 0 && f->precision >= len) ? 1 : 0);
	st_total_len = ((f->width > st_len) ? f->width : st_len);
	i = -1;
	if (nb < 0 && f->zero == 1)
		ft_putchar_fd('-', 1);
	if (f->tiret == 0 && (i = -1))
		while (++i < st_total_len - st_len)
			ft_putchar_fd(((f->zero) ? '0' : ' '), 1);
	if (nb < 0 && f->zero == 0 && (i = -1))
		ft_putchar_fd('-', 1);
	i = -1;
	while (++i < st_len - len)
		ft_putchar_fd('0', 1);
	if ((f->point && f->precision == 0) && nb == 0)
		ft_putchar_fd(' ', 1);
	else
		ft_putnbr_fd(((nb < 0) ? -nb : nb), 1);
	if (f->tiret == 1 && (i = -1))
		while (++i < st_total_len - st_len)
			ft_putchar_fd(' ', 1);
	return (st_total_len);
}
