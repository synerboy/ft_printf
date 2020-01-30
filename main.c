#include "ft_printf.h"
#define INCLUDE "%100.20d", 0
int main(void)
{
	char *p;

	p = "bonjourlesamis";
	ft_printf(INCLUDE);
	printf("|END\n");
	printf(INCLUDE);
	printf("|END\n");

}