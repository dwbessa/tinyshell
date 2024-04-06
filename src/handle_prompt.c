/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:41:11 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/06 15:25:03 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_prompt(char *prompt, char **arg, char *pwd, t_list **env)
{
	extern unsigned int	g_exit_status;

	arg = ft_split(prompt, ' ');
	add_history(prompt);
	if (is_builtin(arg, prompt, env, pwd))
	{
		free_matrix(arg);
		return ;
	}
	else if (!ft_strncmp(arg[0], "$?", 3))
		printf("%d: command not found\n", g_exit_status);
	else if (exec_command(arg, env))
	{
		free_matrix(arg);
		return ;
	}
}
