#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*char_src;
	unsigned char		*char_dest;
	size_t				i;

	if (!src && !dest)
		return (NULL);
	char_src = (const unsigned char *)src;
	char_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return ((void *)char_dest);
}
