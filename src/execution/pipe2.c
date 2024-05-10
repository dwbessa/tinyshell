/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exec_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:49:23 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/10 15:10:11 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_bin_exec_pipe(t_word *node, t_list *env_lst)
{
	char		*cmd;
	char		**mat;
	char		**env_mat;

	if (!node)
		return ;
	cmd = use_path(node->word, env_lst);
	if (!cmd)
		exit(127);
	signal(SIGQUIT, SIG_DFL);
	if (node->fd_out != STDOUT_FILENO)
		dup2(node->fd_out, STDOUT_FILENO);
	if (node->fd_in != STDIN_FILENO)
		dup2(node->fd_in, STDIN_FILENO);
	ms_close_all_fd(node->head);
	mat = transform_list(node);
	env_mat = env_to_matrix(env_lst);
	execve(cmd, mat, env_mat);
	return ;
}

int	ms_bin_exec(t_word *node, t_list *env_lst)
{
	char		**mat;
	char		**env_mat;

	if (!node)
		return (0);
	node->word = use_path(node->word, env_lst);
	if (!node->word)
		return (-1);
	node->pid = fork();
	if (node->pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		if (node->fd_out != STDOUT_FILENO)
			dup2(node->fd_out, STDOUT_FILENO);
		if (node->fd_in != STDIN_FILENO)
			dup2(node->fd_in, STDIN_FILENO);
		ms_close_all_fd(node->head);
		mat = transform_list(node);
		env_mat = env_to_matrix(env_lst);
		execve(node->word, mat, env_mat);
		return (0);
	}
	return (0);
}
