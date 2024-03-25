/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:28:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 23:12:34 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_export(char **arg, t_list **env)
{
	t_list	*node;
	int		i;

	i = 1;
	while (arg[i])
	{
		if (ft_isdigit(arg[i][0]))
		{
			printf("minishell: export: `%s`: not a valid identifier\n", arg[i]);
			return ;
		}
		node = ft_lstnew(ft_strdup(arg[i]));
		if (!node)
		{
			ft_lstclear(&node, free);
			return ;
		}
		ft_lstadd_back(env, node);
		i++;
	}
}

//export with no options and arguments (arg[1] == null) list all env variables
//sorted alphabetically
//export with a KEY that already exists, should update its VALUE
