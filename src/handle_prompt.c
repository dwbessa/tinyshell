/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:41:11 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 15:08:48 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

void	handle_prompt(char *prompt, char **arg, char *pwd, t_list **env)
{
	char	**new_arg;

	arg = ft_split(prompt, ' ');
	add_history(prompt);
	new_arg = expand_prompt(arg, env);
	if (!is_builtin(new_arg, prompt, env, pwd))
		exec_command(new_arg, env);
	free_matrix(new_arg);
}
