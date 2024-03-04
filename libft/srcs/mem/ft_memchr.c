/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:44:07 by dbessa            #+#    #+#             */
/*   Updated: 2023/09/02 16:16:36 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
