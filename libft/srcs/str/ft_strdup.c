#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		index;
	char	*d;

	index = 0;
	d = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!d)
		return (NULL);
	while (src[index])
	{
		d[index] = src[index];
		index++;
	}
	d[index] = '\0';
	return (d);
}
