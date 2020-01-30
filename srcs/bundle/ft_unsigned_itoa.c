#include "../../ft_printf.h"

char		*ft_unsigned_itoa(unsigned int n)
{
	char			*new;
	char			*tmp;
	unsigned int	ctnum;

	ctnum = ft_width_nb_unsigned(n);
	if (!(new = (char *)ft_calloc(ctnum, sizeof(char))))
		return (NULL);
	tmp = new + (ctnum - 2);
	if (!n)
		*new = '0';
	while (n)
	{
		*tmp = (n % 10) + '0';
		n /= 10;
		tmp--;
	}
	if (tmp == new && *new != '0')
		*tmp = '-';
	return (new);
}