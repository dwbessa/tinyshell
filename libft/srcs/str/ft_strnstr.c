#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!big || !little) && !len)
		return (NULL);
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0')
	{
		j = 0;
		while ((big[i + j] == little[j]) && (i + j < len))
		{
			if (big[i + j] == '\0' && little[j] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}
