/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:10:27 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 15:33:35 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_putpointer_fd(__uint128_t n, int fd)
{
	if (n <= 9)
		ft_putchar_fd((n + '0'), fd);
	else if (n >= 10 && n <= 16)
		ft_putchar_fd(('a' - 10) + n, fd);
	else if (n > 16)
	{
		ft_putpointer_fd(n / 16, fd);
		ft_putpointer_fd(n % 16, fd);
	}
}

void	ft_putpointer_long_fd(unsigned long n, int fd)
{
	if (n <= 9)
		ft_putchar_fd((n + '0'), fd);
	else if (n >= 10 && n <= 15)
	{
		ft_putchar_fd(('a' - 10) + n, fd);
	}
	else if (n > 15)
	{
		ft_putpointer_fd(n / 16, fd);
		ft_putpointer_fd(n % 16, fd);
	}
}
