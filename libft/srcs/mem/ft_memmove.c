/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:37:24 by dbessa            #+#    #+#             */
/*   Updated: 2023/10/22 13:06:00 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
