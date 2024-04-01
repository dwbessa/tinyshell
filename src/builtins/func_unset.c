/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:54:42 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/30 15:32:27 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unsetting_env(t_list *prev, t_list *curr, char **arg, t_list **env)
{
	t_list	*next;
	char	*content;
	int		len;

	while (curr)
	{
		next = curr->next;
		content = (char *)curr->content;
		len = ft_strlen(*arg);
		if (!ft_strncmp(*arg, curr->content, len)
			&& (content[len] == '=' || content[len] == '\0'))
		{
			if (prev)
				prev->next = curr->next;
			else
				*env = curr->next;
			ft_lstdelone(curr, free);
			break ;
		}
		prev = curr;
		curr = next;
	}
}

void	func_unset(char **arg, t_list **env)
{
	t_list	*prev;
	t_list	*curr;

	arg++;
	if (!*arg)
		return ;
	while (*arg)
	{
		prev = NULL;
		curr = *env;
		unsetting_env(prev, curr, arg, env);
		arg++;
	}
}
