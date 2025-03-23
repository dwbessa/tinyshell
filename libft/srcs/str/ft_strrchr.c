#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	if (j == -1)
	{
		if (c == '\0')
			return ((char *)&s[i]);
		return (NULL);
	}
	return ((char *)&s[j]);
}
