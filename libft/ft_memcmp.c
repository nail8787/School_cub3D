#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				diff;
	size_t			index;
	unsigned char	*buf_s1;
	unsigned char	*buf_s2;

	index = 0;
	buf_s1 = (unsigned char *)s1;
	buf_s2 = (unsigned char *)s2;
	while (index < n)
	{
		if (buf_s1[index] != buf_s2[index])
		{
			diff = buf_s1[index] - buf_s2[index];
			return (diff);
		}
		else
			index++;
	}
	return (0);
}
