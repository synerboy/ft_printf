/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:03 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/06 16:27:39 by vabrageo         ###   ########.fr       */
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

void			ft_display_pt_show(t_flags *f, int *tt, int *len, char *st)
{
	int 		i;

	i = -1;
	if (f->tiret == 0)
		while (++i < (tt - len - 2))
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(st, 1);
	if (f->tiret == 1)
		while (++i < (tt - len - 2))
			ft_putchar_fd(' ', 1);
}

int				ft_display_pointer(t_flags *f, char *pt)
{
	u_int32_t	tmp;
	int			len;
	char		*forfree;
	int			st_len;
	int			st_total_len;

	len = 0;
	tmp = (u_int32_t)pt;
	st_total_len = 0;
	if (pt)
	{
		forfree = ft_itoa_base((u_int32_t)(tmp), 16);
		len = ft_strlen(forfree);
		st_len = len + 2;
		st_total_len = ((f->width > st_len) ? f->width : st_len);
		ft_display_pt_show(f, &st_total_len, &len, forfree);
		free(forfree);
	}
	else
		return (ft_show_result_null(f));
	return (st_total_len);
}
