/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:21:46 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/21 18:05:03 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlchr(const char *s, char c)
{
	int	wlen;

	wlen = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		wlen++;
	}
	return (wlen);
}

static int	ft_countword(const char *s, char c)
{
	int	check;
	int	cw;

	check = 0;
	cw = 0;
	while (*s)
	{
		check = 1;
		while (*s && *s++ != c)
		{
			if (check)
			{
				check = 0;
				cw++;
			}
		}
	}
	return (cw);
}

static void	allocate_split(int error, char const *s, char c, char **new)
{
	int		i;
	int		start;
	int		cw;
	int		lenw;

	cw = ft_countword(s, c);
	start = -1;
	while (++start < cw)
	{
		while (s && *s == c)
			s++;
		if (*s)
		{
			lenw = ft_strlchr(s, c);
			new[start] = (char *)malloc(((lenw + 1) * sizeof(char)));
			if (!(new[start]))
				if (!(error = 1))
					break ;
			i = 0;
			while (*s && *s != c)
				new[start][i++] = *(s++);
			new[start][i] = '\0';
		}
	}
}

char		**ft_split(char const *s, char c)
{
	int		cw;
	char	**new;
	int		error;

	error = 0;
	if (!s)
		return (NULL);
	cw = ft_countword(s, c);
	if (!(new = (char **)ft_calloc(sizeof(char *), cw + 1)))
		return (NULL);
	new[cw] = NULL;
	allocate_split(error, s, c, new);
	if (error)
	{
		while (*new)
			free(*new++);
		free(new);
		return (NULL);
	}
	return (new);
}
