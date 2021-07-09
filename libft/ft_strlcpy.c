#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	res;
	size_t	index;

	index = 0;
	res = ft_strlen(src);
	if (size > 0)
	{
		while (index < size - 1 && src[index] != '\0')
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (res);
}
