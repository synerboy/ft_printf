/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabrageo <vabrageo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:48:12 by vabrageo          #+#    #+#             */
/*   Updated: 2020/02/11 11:40:52 by vabrageo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	short			tiret;
	short			zero;
	short			point;
	short			stars_width;
	short			stars_precision;
	short			percent;
	char			type;
	int				precision;
	int				width;
	int				tmp;
	int				tmp2;
	int				tmp3;
	unsigned int	unsignedint_tmp;
	short			widthneg;

}					t_flags;

int					ft_printf(const char *st, ...);
void				ft_print_flag(t_flags flags);
int					ft_parsing(char *c, int *i, va_list args);
int					ft_format(va_list args, char type, t_flags *flags);
int					ft_display_int(int nb, t_flags *flags);
void				ft_putstr_len_fd(char *s, int len, int fd);
int					ft_atoi_count(const char *str, int *o);
int					ft_width_nb_64(__uint128_t n);
int					ft_width_nb(int n);
int					ft_width_nb_unsigned(unsigned int n);
int					ft_width_nb_long(unsigned long n);
int					ft_display_c(char c, t_flags *flags);
int					ft_display_unsigned_int(unsigned int nb, t_flags *f);
char				*ft_unsigned_itoa(unsigned int n);
int					ft_display_pointer(t_flags *flags, char *pt);
void				ft_putpointer_fd(__uint128_t n, int fd);
void				ft_putpointer_long_fd(unsigned long n, int fd);
void				ft_putpointermaj_fd(__uint128_t n, int fd);
int					ft_display_string(char *c, t_flags *flags);
int					ft_display_hexa(t_flags *flags, char *hex, int maj);
int					ft_display_percent(char c, t_flags *f);
#endif
