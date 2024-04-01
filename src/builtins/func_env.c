/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:47:10 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 22:39:00 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_env_lst(void)
{
	extern char	**environ;
	t_list		*var;
	t_list		*env;
	int			i;

	i = 0;
	env = NULL;
	while (environ[i])
	{
		var = ft_lstnew(ft_strdup(environ[i]));
		if (!var)
		{
			ft_lstclear(&var, free);
			return (NULL);
		}
		ft_lstadd_back(&env, var);
		i++;
	}
	return (env);
}

void	func_env(t_list **env)
{
	t_list	*current;
	extern unsigned int	g_exit_status;

	current = *env;
	if (!current)
		return ;
	while (current != NULL)
	{
		ft_putendl_fd(current->content, 1);
		current = current->next;
	}
	g_exit_status = 0;
}
