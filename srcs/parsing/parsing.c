/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 16:16:59 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 19:08:16 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void		ft_parsing_engine(t_flags flags, char *c, int *o, va_list args)
{
	while (*(c + *o) == '0' || *(c + *o) == '-')
	{
		if (*(c + *o) == '0')
			flags.zero = 1;
		if (*(c + *o) == '-')
			flags.tiret = 1;
		*o = *o + 1;
	}
	if (flags.tiret && flags.zero)
		flags.zero = 0;
	if (*(c + *o) >= '1' && *(c + *o) <= '9')
	{
		flags.width = ft_atoi_count(c + *o, o);
	}
	if (*(c + *o) == '*')
	{
		flags.width = va_arg(args, int);
		flags.stars_width = 1;
		*o = *o + 1;
	}
}

void		ft_parsing_engine2(t_flags flags, char *c, int *o, va_list args)
{
	if (*(c + *o) == '.')
	{
		flags.point = 1;
		if (*(c + *o + 1) == '*' && *o++)
		{
			flags.stars_precision = 1;
			flags.precision = va_arg(args, int);
		}
		else
			flags.precision = ft_atoi_count(c + *o + 1, o);
		*o = *o + 1;
	}
}

int			ft_parsing(char *c, int *i, va_list args)
{
	t_flags	flags;
	int		o;

	(void)i;
	flags = (t_flags){0};
	o = 1;
	ft_parsing_engine(flags, c, &o, args);
	ft_parsing_engine2(flags, c, &o, args);
	if (*(c + o) == 'c' || *(c + o) == 's' || *(c + o) == 'p' || *(c + o) == 'd'
	|| *(c + o) == 'i' || *(c + o) == 'u' || *(c + o) == 'x'
	|| *(c + o) == 'X' || *(c + o) == '%')
	{
		flags.type = *(c + o);
		ft_format(args, flags.type, &flags);
		return (o);
	}
	return (0);
}
