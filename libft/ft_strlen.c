#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	res;
	int		i;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		res++;
		i++;
	}
	return (res);
}
