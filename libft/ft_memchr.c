#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buf;

	buf = (unsigned char *)s;
	while (n--)
	{
		if (*buf == (unsigned char)c)
			return (buf);
		else
			buf++;
	}
	return (NULL);
}
