/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:28:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/04 10:36:47 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*add_declare(void *content)
{
	char	*str_content;

	str_content = (char *)content;
	str_content = ft_strjoin("declare -x ", str_content);
	return (str_content);
}

void	sort_env(t_list *env)
{
	t_list	*export_env;
	t_list	*export_lst;

	export_env = ft_lstcopy(env);
	if (!export_env)
		return ;
	ft_sortlist(export_env, ft_strcmp);
	export_lst = ft_lstmap(export_env, add_declare, free);
	ft_lstclear(&export_env, free);
	func_env(&export_lst);
	ft_lstclear(&export_lst, free);
}

int	update_var(char *arg, t_list *env)
{
	t_list	*aux;
	int		j;

	aux = env;
	while (env)
	{
		j = many_char(env->content, '=');
		if (!ft_strncmp(env->content, arg, j))
		{
			free(env->content);
			env->content = ft_strdup(arg);
			return (1);
		}
		env = env->next;
	}
	env = aux;
	return (0);
}

void	export_cmd(char **arg, t_list *env)
{
	t_list	*node;

	while (*arg)
	{
		if (ft_isdigit(**arg))
		{
			printf("minishell: export: `%s`: not a valid identifier\n", *arg);
			arg++;
			continue ;
		}
		if (update_var(*arg, env))
		{
			arg++;
			continue ;
		}
		node = ft_lstnew(ft_strdup(*arg));
		if (!node)
		{
			ft_lstclear(&node, free);
			return ;
		}
		ft_lstadd_back(&env, node);
		arg++;
	}
}

int	func_export(char **arg, t_list *env)
{
	extern unsigned int	g_exit_status;

	arg++;
	if (!*arg)
	{
		sort_env(env);
		return (1);
	}
	export_cmd(arg, env);
	g_exit_status = 0;
	return (1);
}
