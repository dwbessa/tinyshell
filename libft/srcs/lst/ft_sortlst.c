/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:25:17 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/30 14:58:56 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sortlist(t_list *lst, int (*cmp)(const char *, const char *))
{
	char	*swap;
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while ((lst)->next != NULL)
	{
		if (((*cmp)((lst)->content, (lst)->next->content)) > 0)
		{
			swap = (lst)->content;
			(lst)->content = (lst)->next->content;
			(lst)->next->content = swap;
			lst = tmp;
		}
		else
			lst = (lst)->next;
	}
	lst = tmp;
}
