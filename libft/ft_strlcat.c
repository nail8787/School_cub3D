#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	res;

	if (size < ft_strlen(dst) + 1)
		res = size + (size_t)ft_strlen(src);
	else
		res = (size_t)ft_strlen(dst) + (size_t)ft_strlen(src);
	index = (size_t)ft_strlen(dst);
	if (size > 0)
	{
		while ((index < size - 1) && *src != '\0')
		{
			dst[index] = *src;
			src++;
			index++;
		}
		dst[index] = '\0';
	}
	return (res);
}
