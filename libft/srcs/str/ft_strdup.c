/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 15:43:19 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/30 10:52:32 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
