#include "../../ft_printf.h"

void ft_print_flag(t_flags flags)
{
	printf("\n----------------------\n");
	printf("*FLAGS DISCOVER DEBUG* \n");
	printf("----------------------\n");
	printf(" 0 : %d", flags.zero);
	printf("\n - : %d \n", flags.tiret);
	printf("\n %% : %d", flags.percent);
	printf("\n . : %d\n", flags.point);
	printf("----------------------\n");
	printf(" WIDTH : %d \n", flags.width);
	printf(" PRECISION : %d ", flags.precision);
	printf("\n PRECISION_WIDTHOINT : %d ", flags.stars_width);
	printf("\n PRECISION_PRECISION : %d ", flags.stars_precision);
	printf("\n TYPE : [%c] \n", flags.type);
	printf("----------------------\n");
}
int ft_parsing(char *c, int *i, va_list args)
{
	t_flags	flags;
	flags = (t_flags){0};
	(void)args;
	int o;

	(void)i;
	o = 1;
	//(void)flags;
	while (*(c + o) == '0' || *(c + o) == '-')
	{
		if (*(c + o) == '0')
			flags.zero = 1;
		if (*(c + o) == '-')
			flags.tiret = 1;
		o++;
	}
	if (flags.tiret && flags.zero)
		flags.zero = 0;
	if (*(c + o) >= '1' && *(c + o) <= '9')
	{
		flags.width = ft_atoi_count(c + o, &o);
	}
	if (*(c + o) == '*')
	{
		flags.width = va_arg(args, int);
		flags.stars_width = 1;
		o++;
	}
	if (*(c + o) == '.')
	{
		flags.point = 1;
		if (*(c + o + 1) == '*' && o++)
		{
			flags.stars_precision = 1;
			flags.precision = va_arg(args, int);
		}
		else
			flags.precision = ft_atoi_count(c + o + 1, &o);
		o++;
	}
	if (*(c + o) == 'c' || *(c + o) == 's' || *(c + o) == 'p' || *(c + o) == 'd'
	|| *(c + o) == 'i' || *(c + o) == 'u' || *(c + o) == 'x' || *(c + o) == 'X' || *(c + o)  == '%')
	{
		flags.type = *(c + o);
		ft_print_flag(flags);
		ft_format(args, flags.type, &flags);
		return (o);
	}
	return (0);
}