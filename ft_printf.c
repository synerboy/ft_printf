/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:26 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 19:12:06 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list	args;
	char	*tmp;
	char 	*st;
	int		i;

	i = 0;
	st = ft_strdup(str);
	ft_strlcpy(st, str, ft_strlen(str) + 1);
	tmp = st;
	va_start(args, str);
	while (*st)
	{
		if (*st == '%')
		{
			ft_putstr_len_fd(tmp, st - tmp, 1);
			i += (st - tmp);
			st += ft_parsing(st, &i, args);
			tmp = st + 1;
		}
		st++;
	}
	if (tmp != st)
	{
		ft_putstr_len_fd(tmp, st - tmp, 1);
		i += (st - tmp);
	}
	va_end(args);
	return (i);
}
