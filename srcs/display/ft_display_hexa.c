/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:10:55 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/02 15:03:04 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_display_hexa(t_flags *f, char *hex, int maj)
{
	int len;
	int	st_len;
	int	st_total_len;
	int i;
	char *forfree;
	unsigned long tmp;

	tmp = (unsigned long)hex;
	forfree = ((maj == 1) ? (ft_itoa_base_maj((long long)(tmp), 16)) 
	: (ft_itoa_base((long long)(tmp), 16)));
	len = ft_strlen(forfree);
	if (f->zero && f->width > 0 && f->point)
		f->zero = 0;
	f->precision = ((f->precision < 0) ? 0 : f->precision);
	f->precision = (f->zero && f->width > len) ? f->width - len : f->precision;
	st_len = (((f->precision > len) ? f->precision : len));
	st_total_len = ((f->width > st_len) ? f->width : st_len);
	i = -1;
	if (f->tiret == 0 && (i = -1))
		while (++i < st_total_len - st_len)
			ft_putchar_fd(' ', 1);
	i = -1;
	while (++i < st_len - len)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(forfree, 1);
	if (f->tiret == 1 && (i = -1))
		while (++i < st_total_len - st_len)
			ft_putchar_fd(' ', 1);
	return (st_total_len);
}
