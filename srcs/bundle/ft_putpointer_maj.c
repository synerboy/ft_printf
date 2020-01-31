/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:10:34 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 15:07:18 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

void	ft_putpointermaj_fd(__uint128_t n, int fd)
{
	if (n <= 9)
		ft_putchar_fd((n + '0'), fd);
	else if (n >= 10 && n <= 16)
	{
		ft_putchar_fd(('A' - 10) + n, fd);
	}
	else if (n > 16)
	{
		ft_putpointermaj_fd(n / 16, fd);
		ft_putpointermaj_fd(n % 16, fd);
	}
}
