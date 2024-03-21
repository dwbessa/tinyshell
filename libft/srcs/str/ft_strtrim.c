/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:56:40 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/21 15:51:49 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	size_t	i;
	char	*trimmed;

	if (!s1 || !set)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	trimmed = ft_substr(s1, 0, i + 1);
	if (!trimmed)
		return (NULL);
	return (trimmed);
}
