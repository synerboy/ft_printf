#include "ft_printf.h"
#define INCLUDE "%0s", "bonjour"
int main(void)
{
	char *p;

	p = "bonjourlesamis";
	ft_printf(INCLUDE);
	printf("|END\n");
	printf(INCLUDE);
	printf("|END\n");

}