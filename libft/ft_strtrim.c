#include "libft.h"

static int		check_from_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		else
			set++;
	}
	return (0);
}

static int		trim_from_back(size_t len, char const *s1, char const *set)
{
	int		res;

	while (len != 0)
	{
		res = check_from_set(s1[len - 1], set);
		if (res == 0)
			break ;
		else if (res == 1)
			len--;
	}
	return (len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	index_start;
	size_t			len;
	int				res;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	index_start = 0;
	while (s1[index_start] != '\0')
	{
		res = check_from_set(s1[index_start], set);
		if (res == 0)
			break ;
		else if (res == 1)
			index_start++;
	}
	if (s1[index_start] == '\0')
		return (ft_substr(s1, index_start, 0));
	len = trim_from_back(len, s1, set);
	return (ft_substr(s1, index_start, (len - index_start)));
}
