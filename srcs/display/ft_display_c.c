/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:10:51 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 12:10:52 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_display_c(char c, t_flags *flags)
{
	int tmp_w;

	tmp_w = flags->width;
	if (tmp_w < 0)
	{
		flags->tiret = 1;
		tmp_w = -tmp_w;
	}
	if (flags->tiret == 0)
		while (tmp_w-- > 1)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	if (flags->tiret)
		while (tmp_w-- > 1)
			ft_putchar_fd(' ', 1);
}
