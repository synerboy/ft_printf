#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct	s_flags
{
	short	tiret;
	short	zero;
	short	point;
	short	stars_width;
	short	stars_precision;
	short	percent;
	char	type;
	int		precision;
	int		width;

}				t_flags;

int				ft_printf(char *st, ...);
void			ft_print_flag(t_flags flags);
int				ft_parsing(char *c, int *i, va_list args);
int				ft_format(va_list args, char type, t_flags *flags);
void			ft_display_int(int nb, t_flags *flags);
void			ft_putstr_len_fd(char *s, int len, int fd);
int				ft_atoi_count(const char *str, int *o);
int				ft_width_nb16(__uint64_t n);
int				ft_width_nb(int n);
int				ft_width_nb_unsigned(unsigned int n);
void			ft_display_c(char c, t_flags *flags);
void			ft_display_unsigned_int(unsigned int nb, t_flags *flags);
char			*ft_unsigned_itoa(unsigned int n);
void			ft_display_pointer(t_flags *flags, char *pt);
void			ft_putpointer_fd(__uint64_t n, int fd);
void			ft_display_string(char *c, t_flags *flags);
#endif