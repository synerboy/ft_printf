/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:03 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/02 16:40:33 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int				ft_show_result_null(t_flags *flags)
{
	if (flags->point && flags->precision == 0)
	{
		flags->point = 0;
		flags->precision = 0;
		ft_display_string("0x", flags);
		return (2);
	}
	else
	{
		flags->point = 0;
		flags->precision = 0;
		ft_display_string("0x0", flags);
		return (3);
	}
}

int					ft_display_pointer(t_flags *f, char *pt)
{
	unsigned long	tmp;
	int				len;
	char			*forfree;
	int				st_len;
	int				st_total_len;
	int				i;

	len = 0;
	tmp = (unsigned long)pt;
	st_total_len = 0;
	if (pt)
	{
		forfree = ft_itoa_base((long long)(tmp), 16);
		len = ft_strlen(forfree);
		st_len = len + 2;	
		i = -1;
		st_total_len = ((f->width > st_len) ? f->width : st_len);
		if (f->tiret == 0)
			while (++i < (st_total_len - len - 2))
				ft_putchar_fd(' ', 1);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(forfree, 1);
		if (f->tiret == 1)
			while (++i < (st_total_len - len - 2))
				ft_putchar_fd(' ', 1);
		free(forfree);
	}
	else
		return (ft_show_result_null(f));
	return (st_total_len);
}
