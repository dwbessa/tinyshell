/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:11:30 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/13 00:53:47 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	return ;
}

void	close_sentence_fd(t_word *prompt)
{
	while (prompt && prompt->flag != MS_PIPE)
	{
		if (prompt->fd_in != STDIN_FILENO)
			close(prompt->fd_in);
		if (prompt->fd_out != STDOUT_FILENO)
			close(prompt->fd_out);
		prompt = prompt->next;
	}
	return ;
}

void	close_fds(t_word *prompt)
{
	while (prompt)
	{
		if (prompt->fd_in != STDIN_FILENO)
			close(prompt->fd_in);
		else if (prompt->fd_out != STDOUT_FILENO)
			close(prompt->fd_out);
		prompt = prompt->next;
	}
	return ;
}

t_word	*get_next_command_pipe(t_word *prompt)
{
	while (prompt)
	{
		if (prompt->flag == MS_PIPE)
			return (prompt->next);
		prompt = prompt->next;
	}
	return (prompt);
}
