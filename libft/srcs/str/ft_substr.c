/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:24:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/01/30 10:50:20 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	unsigned int	s_len;
	unsigned int	max_len;
	char			*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start < s_len)
		max_len = s_len - start;
	if (start >= s_len)
		max_len = 0;
	if (max_len > len)
		max_len = len;
	sub = (char *)malloc((max_len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, max_len + 1);
	return (sub);
}
