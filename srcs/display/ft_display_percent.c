/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:41:06 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/06 16:42:51 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int		ft_display_percent(char c, t_flags *f)
{
	int	st_len;
	int	st_total_len;
	int	i;

	i = -1;
	st_len = 1;
	st_total_len = (f->width > st_len) ? f->width : st_len;
	while (f->tiret == 0 && ++i < st_total_len - st_len)
		ft_putchar_fd((f->zero) ? '0' : ' ', 1);
	ft_putchar_fd(c, 1);
	while (f->tiret && ++i < st_total_len - st_len)
		ft_putchar_fd(' ', 1);
	return (st_total_len);
}
