#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*m_dst;
	const unsigned char *m_src;

	m_src = (const unsigned char *)src;
	m_dst = (unsigned char *)dst;
	if (m_dst == NULL && src == NULL)
		return (NULL);
	if (len == 0)
		return (dst);
	if (m_dst == m_src)
		return (dst);
	if (m_dst > m_src)
	{
		while (len)
		{
			len--;
			m_dst[len] = m_src[len];
		}
	}
	else if (m_dst < m_src)
	{
		while (len--)
			*m_dst++ = *m_src++;
	}
	return (dst);
}
