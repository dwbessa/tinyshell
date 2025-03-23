#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || (nptr[i] == ' '))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i + 1] == '-' || nptr[i +1] == '+')
			return (0);
		else if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = (res * 10) + (nptr[i++] - '0');
	return (res * sign);
}
