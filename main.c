#include "ft_printf.h"
#define INCLUDE "%-10.1c", 'c'
int main(void)
{
	char *p;

	p = "bonjourlesamis";
	ft_printf(INCLUDE);
	printf("|END\n");
	printf(INCLUDE);
	printf("|END\n");

}