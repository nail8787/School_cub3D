
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*buf;

	if (!s)
		return (NULL);
	index = 0;
	buf = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (s[index] != '\0')
	{
		buf[index] = f(index, s[index]);
		index++;
	}
	buf[index] = '\0';
	return (buf);
}
