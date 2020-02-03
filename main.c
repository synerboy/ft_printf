/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:38 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/02 16:40:56 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MEME 178765
#define INCLUDE "%*.*d", 120, -10, 420
int main(void)
{
	ft_printf("======================= PRINTF TESTING =======================\n");
	//char *p = "Bonjour les pu";
	ft_printf("|RET : %d", ft_printf(INCLUDE));
	printf("\n");
	printf("|RET : %d", printf(INCLUDE));
	printf("\n");
}