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

void	ft_display_string_cfg(t_flags *f, int len, int *tmp_len, int *tmp_w)
{
	if (f->precision < 0 && !(f->point = 0))
		f->precision = 0;
	if (f->width < 0)
	{
		f->tiret = 1;
		f->width = -f->width;
	}
	if (f->precision < len && f->point)
	{
		*tmp_len = f->precision;
	}
	if (f->width >= f->precision && f->width > len)
		*tmp_w = f->width - len;
	if (f->width >= f->precision && f->precision < len && f->point)
	{
		*tmp_len = f->precision;
		*tmp_w = (f->width - *tmp_len);
	}
}

void	ft_display_string_cfg2(t_flags *f, int len, int *tmp_len, int *tmp_w)
{
	if (f->width < f->precision && f->width < len)
		*tmp_w = 0;
	if (f->width <= f->precision && f->width > len)
		*tmp_w = f->width - len;
	if (f->width && f->point == 0 && f->width < len)
	{
		*tmp_w = 0;
		*tmp_len = len;
	}
	if (f->width >= len)
	{
		*tmp_len = len;
		if (f->precision < len && f->point)
			*tmp_len = f->precision;
		*tmp_w = f->width - *tmp_len;
	}
}

void	ft_display_string(char *c, t_flags *flags)
{
	int len;
	int tmp_w;
	int tmp_len;

	len = ft_strlen(c);
	tmp_len = len;
	tmp_w = flags->width;
	ft_display_string_cfg(flags, len, &tmp_len, &tmp_w);
	ft_display_string_cfg2(flags, len, &tmp_len, &tmp_w);
	if (flags->tiret == 0)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
	ft_putstr_len_fd(c, tmp_len, 2);
	if (flags->tiret)
		while (tmp_w-- > 0)
			ft_putchar_fd(' ', 2);
}
