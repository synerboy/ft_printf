/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:26 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/02 16:33:26 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_end(char *tmp, char *st, int *i)
{
	ft_putstr_len_fd(tmp, st - tmp, 1);
	*i += (st - tmp);
}

void		ft_printf_engine(va_list args, char **st, char **tmp, int *i)
{
	if (**st == '%')
	{
		ft_putstr_len_fd(*tmp, *st - *tmp, 1);
		*i += ((*st) - *tmp);
		*st += ft_parsing(*st, i, args);
		*tmp = (*st) + 1;
	}
	(*st)++;
}

int			ft_printf(const char *str, ...)
{
	va_list	args;
	char	*tmp;
	char	*st;
	int		i;
	char	*tmpst;

	i = 0;
	if (!(st = ft_strdup(str)))
		return (0);
	tmpst = st;
	ft_strlcpy(st, str, ft_strlen(str) + 1);
	tmp = st;
	va_start(args, str);
	while (*st)
		ft_printf_engine(args, &st, &tmp, &i);
	if (tmp != st)
		ft_printf_end(tmp, st, &i);
	free(tmpst);
	va_end(args);
	return (i);
}
