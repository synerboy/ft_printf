/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:27:59 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/21 16:10:56 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*navigate;

	if (alst && new)
	{
		navigate = (*alst);
		if (navigate == NULL)
			(*alst) = new;
		else
		{
			while (navigate->next)
				navigate = navigate->next;
			navigate->next = new;
		}
	}
}
