#include "../../ft_printf.h"

void	ft_putpointer_fd(__uint64_t n, int fd)
{
	if (n <= 9)
		ft_putchar_fd((n + '0'), fd);
	else if (n >= 10 && n <= 16)
	{
		ft_putchar_fd(('a' - 10) + n, fd);
	}
	else if (n > 16)
	{
		ft_putpointer_fd(n / 16, fd);
		ft_putpointer_fd(n % 16, fd);
	}
}