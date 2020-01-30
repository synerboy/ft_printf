/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:32:24 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/24 14:39:07 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void *newptr;

	if (nitems == 0 || size == 0)
	{
		nitems = 1;
		size = 1;
	}
	if (!(newptr = (void *)malloc(size * nitems)))
		return (NULL);
	ft_bzero(newptr, size * nitems);
	return (newptr);
}
