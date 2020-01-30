/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:33:04 by vabrageo          #+#    #+#             */
/*   Updated: 2019/10/18 16:18:30 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*init;
	t_list	*beggin;

	beggin = *lst;
	init = *lst;
	tmp = *lst;
	if (!lst || !del)
		return ;
	while (tmp)
	{
		beggin = tmp;
		tmp = tmp->next;
		del(beggin->content);
		free(beggin);
	}
	(*lst) = NULL;
}
