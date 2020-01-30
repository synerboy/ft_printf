/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:25:03 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/20 20:29:53 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ctnum(int n)
{
	int ct;

	ct = 0;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= 10;
		ct++;
	}
	return (ct + 1);
}

char		*ft_itoa(int n)
{
	char	*new;
	char	*tmp;
	int		ctnum;

	ctnum = (n < 0) ? ft_ctnum(n) + 1 : ft_ctnum(n);
	if (!(new = (char *)ft_calloc(ctnum, sizeof(char))))
		return (NULL);
	tmp = new + (ctnum - 2);
	if (!n)
		*new = '0';
	while (n)
	{
		*tmp = ((n < 0) ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
		tmp--;
	}
	if (tmp == new && *new != '0')
		*tmp = '-';
	return (new);
}
