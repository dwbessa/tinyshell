/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:08:33 by dbessa            #+#    #+#             */
/*   Updated: 2023/09/15 22:18:32 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*char_s1;
	const unsigned char	*char_s2;
	size_t				i;

	i = 0;
	char_s1 = (const unsigned char *)s1;
	char_s2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (char_s1[i] != char_s2[i])
			return ((int)(char_s1[i]) - (int)(char_s2[i]));
		i++;
	}
	return (0);
}
