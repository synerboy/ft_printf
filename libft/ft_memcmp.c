/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:09:15 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/24 18:55:42 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*new1;
	const unsigned char		*new2;

	if (s1 == s2 || n == 0)
		return (0);
	new1 = (const unsigned char *)s1;
	new2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*new1 != *new2)
			return (*new1 - *new2);
		if (n)
		{
			new1++;
			new2++;
		}
	}
	return (0);
}
