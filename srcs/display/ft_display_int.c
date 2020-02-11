/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:01 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/11 10:46:34 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_display_int_cfg(t_flags *f, int *len, int *st_len, int *st_ttlen)
{
	int nb;

	nb = f->tmp;
	*len = ft_width_nb((nb < 0) ? -nb : nb) + ((nb < 0) ? 1 : 0);
	*len -= ((*len == 1 && nb == 0 && f->precision == 0
	&& f->point == 1) ? 1 : 0);
	if (f->zero && f->width > 0 && f->point && f->precision >= 0)
		f->zero = 0;
	if ((f->tiret && f->zero) || (f->width <= 0))
		f->zero = 0;
	f->precision = ((f->precision < 0) ? 0 : f->precision);
	f->precision = (f->zero && f->width > *len) ?
	f->width - *len : f->precision;
	*st_len = (((f->precision > *len && f->point) ? f->precision : *len));
	*st_len += ((nb < 0 && f->precision >= *len && f->point) ? 1 : 0);
	*st_ttlen = ((f->width > *st_len) ? f->width : *st_len);
	*st_ttlen -= (nb == -2147483648) ? 1 : 0;
}

void	ft_display_int_show(t_flags *f, int *len, int *ttlen, int *stlen)
{
	int nb;
	int i;

	i = -1;
	nb = f->tmp;
	if (nb < 0 && f->zero == 1 && nb != -2147483648)
		ft_putchar_fd('-', 1);
	if (f->tiret == 0)
		while (++i < *ttlen - *stlen)
			ft_putchar_fd(((f->zero) ? '0' : ' '), 1);
	if (nb < 0 && f->zero == 0 && nb != -2147483648)
		ft_putchar_fd('-', 1);
	i = -1;
	while (++i < (*stlen - *len) && f->width >= 0)
		ft_putchar_fd('0', 1);
	if ((f->point && f->precision == 0) && nb == 0 && *len == 0)
		;
	else
		ft_putnbr_fd(((nb < 0) ? -nb : nb), 1);
	i = -1;
	if (f->tiret == 1)
		while (++i < (*ttlen - *stlen))
			ft_putchar_fd(' ', 1);
}

int		ft_display_int(int nb, t_flags *f)
{
	int len;
	int	st_len;
	int	st_total_len;

	f->tmp = nb;
	ft_display_int_cfg(f, &len, &st_len, &st_total_len);
	ft_display_int_show(f, &len, &st_total_len, &st_len);
	return (st_total_len);
}
