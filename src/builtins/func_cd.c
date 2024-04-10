/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:42:56 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 15:22:52 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	func_cd(char **argument, t_list *env)
{
	extern unsigned int	g_exit_status;

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
