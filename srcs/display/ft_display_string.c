/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:06 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 15:56:24 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_display_string(char *c, t_flags *f)
{
	int	st_len;
	int	st_total_len;
	int	i;

	i = -1;
	st_len = ((f->point && f->precision < (int)ft_strlen(c)) 
	&& (f->precision >= 0)) ? f->precision : ft_strlen(c);
	st_total_len = (f->width > st_len) ? f->width : st_len;
	while (f->tiret == 0 && ++i < st_total_len - st_len)
		ft_putchar_fd(' ', 1);
	ft_putstr_len_fd(c, st_len, 1);
	while (f->tiret && ++i < st_total_len - st_len)
		ft_putchar_fd(' ', 1);
	return (st_total_len);
}
