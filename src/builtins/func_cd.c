/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:42:56 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/06 17:03:50 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	func_cd(char **argument, t_list **envp)
{
	t_list				*env;
	extern unsigned int	g_exit_status;

	env = *envp;
	if (!argument[1])
	{
		while (env != NULL)
		{
			if (!ft_strncmp((char *)(env->content), "HOME=", 5))
			{
				chdir((char *)(env->content + 5));
				break ;
			}
			env = env->next;
		}
	}
	else
	{
		if (chdir(argument[1]) == -1)
		{
			g_exit_status = errno;
			perror("minishell: cd");
		}
	}
	return (1);
}
