/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:51:10 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/10 14:58:10 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_exec_pipe(t_word *node, t_list **env_lst)
{
	node->pid = fork();
	if (node->pid != 0)
		return ;
	ms_bin_exec_pipe(node, *env_lst);
}

int	ms_pipe(t_word *node)
{
	int		fd[2];
	t_word	*cmd;

	while (node)
	{
		while (node && node->flag != MS_PIPE && node->flag != MS_WORD)
			node = node->next;
		cmd = node;
		while (node && node->flag != MS_PIPE)
			node = node->next;
		if (!node)
			return (0);
		if (pipe(fd) == -1)
			return (1);
		cmd->fd_out = fd[1];
		node = node->next;
		cmd = node;
		while (cmd && cmd->flag != MS_PIPE && cmd->flag != MS_WORD)
			cmd = cmd->next;
		if (cmd)
			cmd->fd_in = fd[0];
		else
			ms_close_pipe(fd);
	}
	return (0);
}

void	ms_close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
	return ;
}

void	ms_close_all_fd(t_word *node)
{
	while (node)
	{
		if (node->fd_in != STDIN_FILENO)
			close(node->fd_in);
		else if (node->fd_out != STDOUT_FILENO)
			close(node->fd_out);
		node = node->next;
	}
	return ;
}
