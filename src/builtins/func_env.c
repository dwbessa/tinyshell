/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:47:10 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 15:24:26 by dbessa           ###   ########.fr       */
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

int	func_env(t_list *env)
{
	extern unsigned int	g_exit_status;

	if (!env)
		return (1);
	while (env != NULL)
	{
		ft_putendl_fd(env->content, 1);
		env = env->next;
	}
	g_exit_status = 0;
	return (1);
}
