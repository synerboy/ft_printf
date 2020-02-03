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
	int	st_len; //Taille des char
	int	st_total_len; //Taille total
	//int st_zero; //Taille des zero
	int	i;
	int neg;
	int	zero;

	neg = (nb < 0) ? 1 : 0;
	nb = (neg) ? -nb : nb;
	zero = 0;
	if (f->precision > ft_width_nb(nb))
		zero = f->precision - ft_width_nb(nb);
	i = -1;
	st_len = ((f->point && f->precision < ft_width_nb(nb)) 
	&& (f->precision >= 0)) ? f->precision : ft_width_nb(nb);
	st_total_len = (f->width > st_len) ? f->width : st_len;
	i = 0;
	while (f->tiret == 0 && ++i < (st_total_len - st_len + ((neg > 0) ? 0 : 1)) 
	- zero - ((f->precision < ft_width_nb(nb)) ? (ft_width_nb(nb) - f->precision) : 0))
		ft_putchar_fd(' ', 1);
	if (neg)
		ft_putchar_fd('-', 1);
	i = -1;
	while (++i < zero)
		ft_putchar_fd('0', 1);
	if (nb != 0)
		ft_putnbr_fd(nb, 1);
	while (f->tiret && ++i < st_total_len - st_len)
		ft_putchar_fd(' ', 1);
	return (st_total_len);
}
