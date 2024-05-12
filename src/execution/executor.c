/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:12:04 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/12 04:36:43 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	executor(t_word **lst, t_list **env_lst)
{
	t_word	*prompt;

	prompt = *lst;
	ft_pipe(prompt);
	prompt->env = *env_lst;
	while (prompt)
	{
		exec_pipe(prompt);
		close_sentence_fd(prompt);
		prompt = get_next_command_pipe(prompt);
	}
	return (0);
}
