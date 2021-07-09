#include "libft.h"

static void	clean(char **buf, unsigned int index)
{
	while (index-- > 0)
	{
		free(buf[index]);
	}
	free(buf);
}

static int	num_of_strings(char const *s, char c)
{
	unsigned int	index;
	unsigned int	count;

	count = 1;
	index = 0;
	while (s[index] != '\0')
	{
		while (s[index] == c && s[index] != '\0')
		{
			index++;
		}
		if (s[index] != c && s[index] != '\0')
		{
			count++;
			while (s[index] != c && s[index] != '\0')
				index++;
		}
	}
	return (count);
}

static char	**memalloc(char const *s, char c, char **buf, unsigned int index)
{
	unsigned int	len;

	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (len > 0)
		{
			buf[index] = (char *)ft_calloc((len + 1), sizeof(char));
			if (!buf[index])
			{
				clean(buf, index);
				return (NULL);
			}
			index++;
			len = 0;
		}
	}
	return (buf);
}

char		**ft_split(char const *s, char c)
{
	char			**buf;
	unsigned int	count;
	unsigned int	index;

	if (!s)
		return (NULL);
	index = 0;
	buf = (char **)ft_calloc(num_of_strings(s, c), sizeof(char *));
	if (!buf)
		return (NULL);
	buf = memalloc(s, c, buf, index);
	buf[(num_of_strings(s, c) - 1)] = NULL;
	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			buf[count][index++] = *s++;
		index = 0;
		count++;
	}
	return (buf);
}
