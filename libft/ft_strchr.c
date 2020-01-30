/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:18:26 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/11 23:03:18 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*s;
	unsigned char	cc;

	s = (unsigned char *)str;
	cc = (unsigned char)c;
	while (*s && *s != cc && s++)
		;
	if (*s == cc)
		return ((char *)s);
	return (NULL);
}
