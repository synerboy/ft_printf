/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:38 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/06 15:00:36 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MEME 178765
#define INCLUDE "OU%-.4XrV4B%.*i%0ucYqN78G%XPDD%0.0X78PDD%1.2u%s", 2147483647, 6, 75298336, 2147483647, -2147483647, -2147483647, -1607073528, "bonjour"
int main(void)
{
	//char *p = "test";
	ft_printf("======================= PRINTF TESTING =======================\n");
	ft_printf("|RET : %d", ft_printf(INCLUDE));
	printf("\n");
	printf("|RET : %d", printf(INCLUDE));
	printf("\n");
}