/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:25:03 by vabrageo          #+#    #+#             */
/*   Updated: 2020/01/31 18:49:19 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ctnum(long long n, int base)
{
	int ct;

	ct = 0;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n /= base;
		ct++;
	}
	return (ct + 1);
}

char			*ft_itoa(long long n)
{
	return (ft_itoa_base(n, 10));
}

char			*ft_itoa_base(long long n, size_t base)
{
	static char *base_str = "0123456789abcdef";
	char		*new;
	char		*tmp;
	int			ctnum;

	if (base > 16)
		return (NULL);
	ctnum = (n < 0) ? ft_ctnum(n, base) + 1 : ft_ctnum(n, base);
	if (!(new = (char *)ft_calloc(ctnum, sizeof(char))))
		return (NULL);
	tmp = new + (ctnum - 2);
	if (!n)
		*new = '0';
	while (n)
	{
		*tmp = base_str[((n < 0) ? -(n % base) : (n % base))];
		n /= base;
		tmp--;
	}
	if (tmp == new && *new != '0')
		*tmp = '-';
	return (new);
}

char			*ft_itoa_base_maj(long long n, size_t base)
{
	static char *base_str = "0123456789ABCDEF";
	char		*new;
	char		*tmp;
	int			ctnum;

	if (base > 16)
		return (NULL);
	ctnum = (n < 0) ? ft_ctnum(n, base) + 1 : ft_ctnum(n, base);
	if (!(new = (char *)ft_calloc(ctnum, sizeof(char))))
		return (NULL);
	tmp = new + (ctnum - 2);
	if (!n)
		*new = '0';
	while (n)
	{
		*tmp = base_str[((n < 0) ? -(n % base) : (n % base))];
		n /= base;
		tmp--;
	}
	if (tmp == new && *new != '0')
		*tmp = '-';
	return (new);
}