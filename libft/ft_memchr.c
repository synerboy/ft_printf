/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:09:01 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/21 21:56:53 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int i;

	i = -1;
	while (++i < n)
		if (((const char *)s)[i] == c)
			return (void *)&((const char *)s)[i];
	return (NULL);
}
