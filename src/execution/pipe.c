/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:19:50 by ldantas           #+#    #+#             */
/*   Updated: 2024/05/18 18:27:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_pipe(t_word *prompt)
{
	prompt->pid = fork();
	if (prompt->pid != 0)
		return ;
	bin_exec_pipe(prompt);
}

void	bin_exec_pipe(t_word *prompt)
{
	char		**mat;
	char		**env_mat;

	if (!prompt)
		return ;
	prompt->word = use_path(prompt->word, prompt->env);
	if (!prompt->word)
		exit(127);
	redirect_stdio(prompt);
	close_fds(prompt->head);
	mat = transform_list(prompt);
	env_mat = env_to_matrix(prompt->env);
	if (execve(prompt->word, mat, env_mat) == -1)
	{
		printf("minishell: command not found: %s\n", prompt->word);
		exit(127);
	}
	return ;
}

int	ft_pipe(t_word *prompt)
{
	int		fd[2];
	t_word	*cmd;

	while (prompt)
	{
		while (prompt && prompt->flag != MS_PIPE && prompt->flag != MS_WORD)
			prompt = prompt->next;
		cmd = prompt;
		while (prompt && prompt->flag != MS_PIPE)
			prompt = prompt->next;
		if (!prompt)
			return (0);
		if (pipe(fd) == -1)
			return (1);
		cmd->fd_out = fd[1];
		prompt = prompt->next;
		cmd = prompt;
		while (cmd && cmd->flag != MS_PIPE && cmd->flag != MS_WORD)
			cmd = cmd->next;
		if (cmd)
			cmd->fd_in = fd[0];
		else
			close_pipe(fd);
	}
	return (0);
}

void	wait_cmds(t_word *prompt)
{
	t_word				*aux;
	extern unsigned int	g_exit_status;

	if (!prompt)
		return ;
	aux = prompt;
	while (prompt)
	{
		if (prompt->pid != 0)
			waitpid(prompt->pid, &prompt->ret, 0);
		prompt= prompt->next;
	}
	prompt= aux;
	while (prompt)
	{
		if (prompt->ret >= 0)
			g_exit_status = WEXITSTATUS(prompt->ret);
		prompt= prompt->next;
	}
	return ;
}
