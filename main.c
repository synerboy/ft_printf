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
#define INCLUDE "%*.*s", -10, -2, NULL
#define INCLUDE2 "N2P%%cmDY%%%0*.0d%-c%*.3XqLZV7C73i9PB", 10, -1087841296, '5', 2, 2147483647
int main(void)
{
	ft_printf("======================= PRINTF TESTING =======================\n");
	//char *p = "Bonjour les pupute";
	ft_printf(INCLUDE);
	printf("|END\n");
	printf(INCLUDE);
	printf("|END\n");

	ft_printf(INCLUDE2);
	printf("|END\n");
	printf(INCLUDE2);
	printf("|END\n");
}