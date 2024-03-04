/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:54:47 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/30 10:52:58 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	count1;
	size_t	count2;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	count1 = 0;
	count2 = 0;
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (count1 != ft_strlen(s1))
	{
		s3[count1] = s1[count1];
		count1++;
	}
	while (count2 != ft_strlen(s2))
	{
		s3[count1 + count2] = s2[count2];
		count2++;
	}
	s3[count1 + count2] = '\0';
	return (s3);
}
