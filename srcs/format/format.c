#include "../../ft_printf.h"

int		ft_format(va_list args, char type, t_flags *flags)
{
	(void)args;
	if (type == '%')
		ft_putchar_fd('%', 2);
	if (type == 'd' || type == 'i')
		ft_display_int(va_arg(args, int), flags);
	if (type == 'c')
		ft_display_c(va_arg(args, int), flags);
	if (type == 'u')
		ft_display_unsigned_int(va_arg(args, unsigned int), flags);
	if (type == 'p')
		ft_display_pointer(flags, va_arg(args, char *));
	if (type == 's')
		ft_display_string(va_arg(args, char *), flags);
	return (1);
}