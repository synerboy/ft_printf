#include "../../ft_printf.h"

void	ft_putstr_len_fd(char *s, int len, int fd)
{
	if (!(s))
		return ;
	write(fd, s, len);
}