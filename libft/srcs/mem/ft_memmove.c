#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*char_dest;
	const unsigned char	*char_src;

	if (!src && !dest)
		return (NULL);
	char_dest = (unsigned char *)dest;
	char_src = (const unsigned char *)src;
	if (char_dest < char_src || char_dest >= char_src + n)
	{
		while (n--)
			*char_dest++ = *char_src++;
	}
	else
	{
		char_dest += n;
		char_src += n;
		while (n--)
			*(--char_dest) = *(--char_src);
	}
	return (dest);
}
