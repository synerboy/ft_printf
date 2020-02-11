/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:10:55 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/11 10:45:52 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void				ft_display_hexa_show(t_flags *f, int *len, char *forfree)
{
	int i;

	i = -1;
	if (f->tiret == 0 && (i = -1))
		while (++i < f->tmp2 - f->tmp)
			ft_putchar_fd((f->zero) ? '0' : ' ', 1);
	i = -1;
	while (++i < f->tmp - *len)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(forfree, 1);
	if (f->tiret == 1 && (i = -1))
		while (++i < f->tmp2 - f->tmp)
			ft_putchar_fd(' ', 1);
}

int					ft_display_hexa(t_flags *f, char *hex, int maj)
{
	int				len;
	int				st_len;
	int				st_total_len;
	char			*st;
	u_int32_t		tmp;

	tmp = (u_int32_t)hex;
	st = ((maj == 1) ? (ft_itoa_base_maj((u_int32_t)(tmp), 16))
	: (ft_itoa_base((u_int32_t)(tmp), 16)));
	len = ft_strlen(st);
	len = (len == 1 && st[0] == '0') ? 1 : ft_strlen(st);
	len = (len == 1 && st[0] == '0' && f->precision == 0 && f->point) ? 0 : len;
	st[0] = (len == 0 && st[0] == '0') ? '\0' : st[0];
	f->zero = (f->zero && f->width > 0 && f->point
	&& f->precision >= 0) ? 0 : f->zero;
	f->precision = ((f->precision < 0) ? 0 : f->precision);
	f->precision = (f->zero && f->width > len) ? f->width - len : f->precision;
	st_len = (((f->precision > len) ? f->precision : len));
	st_total_len = ((f->width > st_len) ? f->width : st_len);
	f->tmp = st_len;
	f->tmp2 = st_total_len;
	ft_display_hexa_show(f, &len, st);
	return (st_total_len);
}
