/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 12:11:38 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/02 16:13:50 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define MEME 178765
#define INCLUDE "%p", NULL
#define INCLUDE2 "bonjour %-10%%-0.10%%d OH OUI MY %x, OR, %-10.4s", -189, MEME, "Nonono je ne veut pas oublier"
#define INCLUDE3 "bonjour %-10.40%%-0.10%%s OH OUI MY %x, OR, %19X", "bonjourles pupute", MEME, MEME
#define INCLUDE4 "bonjour %-10.40%%-0.10%%s OH OUI MY %-19.%%8d, OR, %19X", "bonwte98", MEME, MEME
#define INCLUDE5 "Bonjour l%-12.544ses connard%-7c, je suis heur%-17.45d, de f%iiair cec%x", "hohoh ui ji l", 'y', 16543, 78, 89
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

	ft_printf(INCLUDE3);
	printf("|END\n");
	printf(INCLUDE3);
	printf("|END\n");

	ft_printf(INCLUDE4);
	printf("|END\n");
	printf(INCLUDE4);
	printf("|END\n");

	ft_printf(INCLUDE5);
	printf("|END\n");
	printf(INCLUDE5);
	printf("|END\n");
}