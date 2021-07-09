#include "libft.h"

static int		size_of_int(int buf)
{
	unsigned int	count;

	count = 0;
	if (buf == 0)
		return (1);
	if (buf < 0)
		count += 1;
	while (buf != 0)
	{
		buf = buf / 10;
		count++;
	}
	return (count);
}

static char		*fill_arr(int n, char *str, size_t len)
{
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = size_of_int(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[len] = '0';
	if (n == -2147483648)
	{
		str[len--] = '8';
		n = -214748364;
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n > 0)
		fill_arr(n, str, len);
	return (str);
}
