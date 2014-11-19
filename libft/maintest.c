#include <string.h>
#include "libft.h"

int main()
{
	char s1[] = "tata";
	char s2[] = "a";
	char *result;

	result = ft_strstr(s1, s2);
	ft_putstr(result);
	ft_putchar('\n');
	return (0);
}
