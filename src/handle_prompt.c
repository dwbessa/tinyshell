/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:41:11 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/04 17:21:41 by dbessa           ###   ########.fr       */
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
	else if (!ft_strncmp(arg[0], "clear", 6))
		command_env();
}
