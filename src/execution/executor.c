/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:12:04 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/13 01:07:15 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	executor(t_data *data, int have_pipe)
{
	t_word	*prompt;

	prompt = data->prompt;
	ft_pipe(prompt);
	prompt->env = data->env;
	while (prompt)
	{
		if (do_redir(prompt) != 0)
			return 1;
		if (have_pipe)
			exec_pipe(prompt);
		else if (!is_builtin(data))
			exec_command(data);
		close_sentence_fd(prompt);
		prompt = get_next_command_pipe(prompt);
	}
	return (0);
}
