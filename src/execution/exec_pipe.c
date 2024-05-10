/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:17:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/10 15:52:35 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

static void	exec_generic_multiple(t_word *prompt, char **splitted_cmd)
{
	char	*path;
	char 	**envp;

	path = use_path(prompt->word, prompt->env);
	envp = env_to_matrix(prompt->env);
	// single_cmd = transform_list(prompt);
	if (!path)
	{
		ft_putstr_fd("path nao encontrado", 2);
		exit(1);
	}
	execve(path, splitted_cmd, envp);
}

void	exec_multiple(t_word *prompt, char *raw_cmd)
{
	char	**splitted_cmd;

	splitted_cmd = transform_list(prompt);
	if (!raw_cmd[0])
		exit(0);
	else
		exec_generic_multiple(prompt, splitted_cmd);
}