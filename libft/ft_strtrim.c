/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:17:08 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/21 15:51:32 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	lenstr;
	char	*new;

	if (s1)
	{
		while (*s1 && ft_strchr(set, *s1))
			s1++;
		lenstr = ft_strlen(s1);
		while (lenstr != 0 && ft_strchr(set, s1[lenstr - 1]))
			lenstr--;
		if (!(new = malloc(sizeof(char) * lenstr + 1)))
			return (NULL);
		new[lenstr] = '\0';
		ft_memcpy(new, s1, lenstr);
		return (new);
	}
	return (NULL);
}
