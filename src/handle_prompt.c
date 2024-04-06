/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:41:11 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/05 21:24:01 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_prompt(char *prompt, char **arg, char *pwd, t_list **env)
{
	arg = ft_split(prompt, ' ');
	add_history(prompt);
	if (is_builtin(arg, prompt, env, pwd))
	{
		free_matrix(arg);
		return ;
	}
	else if (command_clear(arg, env))
	{
		free_matrix(arg);
		return ;
	}
}
