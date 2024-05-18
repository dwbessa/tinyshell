/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:42:56 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/18 00:33:00 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	func_cd(t_word *prompt)
{
	extern unsigned int	g_exit_status;

	if (!prompt->next)
	{
		while (prompt->env != NULL)
		{
			if (!ft_strncmp((char *)(prompt->env->content), "HOME=", 5))
			{
				chdir((char *)(prompt->env->content + 5));
				break ;
			}
			prompt->env = prompt->env->next;
		}
	}
	else
	{
		if (chdir(prompt->next->word) == -1)
		{
			g_exit_status = errno;
			perror("minishell: cd");
		}
	}
	prompt = prompt->head;
	return (1);
}
