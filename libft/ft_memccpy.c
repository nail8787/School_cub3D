#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t			index;
	unsigned char	*src1;
	unsigned char	*dst1;

	index = 0;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	while (index < n)
	{
		if (src1[index] == (unsigned char)c)
		{
			dst1[index] = src1[index];
			index++;
			return (dst1 + index);
		}
		else
		{
			dst1[index] = src1[index];
			index++;
		}
	}
	return (NULL);
}
