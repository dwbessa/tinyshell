#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*char_s;

	char_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == (unsigned char)c)
			return ((void *)&char_s[i]);
		i++;
	}
	return (NULL);
}
