#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len_needle;

	len_needle = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len-- >= len_needle)
	{
		if (*haystack == *needle &&
				ft_strncmp(haystack, needle, len_needle) == 0)
			return ((char *)haystack);
		else
			haystack++;
	}
	return (NULL);
}
