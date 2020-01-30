/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:29:44 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/22 14:00:46 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;
	int		total_size;

	j = -1;
	i = 0;
	if (!s2 || !s1)
		return (NULL);
	total_size = (ft_strlen(s1) + ft_strlen(s2));
	if (!(new = (char *)malloc((sizeof(char) * total_size + 1))))
		return (NULL);
	while (++j < (int)ft_strlen(s1))
		new[i++] = s1[j];
	j = -1;
	while (++j < (int)ft_strlen(s2))
		new[i++] = s2[j];
	new[i] = '\0';
	return (new);
}
