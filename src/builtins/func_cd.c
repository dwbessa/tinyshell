/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:42:56 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 13:06:11 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_cd(char **argument, t_list *env)
{
	if (!argument[1] || !ft_strncmp(argument[1], "~", 2))
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
		chdir(argument[1]);
}
