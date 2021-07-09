#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *buf;

	buf = NULL;
	while (*s && *s != '\0')
	{
		if (*s == c)
		{
			buf = (char *)s;
			s++;
		}
		else
			s++;
	}
	if (*s == c)
		return (buf = (char *)s);
	return (buf);
}
