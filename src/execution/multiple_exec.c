/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:18:35 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/10 15:24:18 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"


static void	parent(t_word *node)
{
	dup2(node->fd[0], STDIN_FILENO);
	close(node->fd[0]);
	close(node->fd[1]);
}

void	child_process(t_word *node)
{
	if (node->next != NULL)
		dup2(node->fd[1], STDOUT_FILENO);
	close(node->fd[1]);
	close(node->fd[0]);
}

int	ft_multiple_commands(t_data *data)
{
	t_word *node;

	node = data->prompt->head;
	if (node == NULL)
		return (0);
	while (node)
	{
		pipe(node->fd);
		node->pid = fork();
		if (node->pid < 0)
		{
			close(node->fd[1]);
			close(node->fd[0]);
			exit (0);
		}
		if (node->pid == 0)
		{
			child_process(node);
			exec_multiple(node, node->word);
		}
		parent(node);
		node = node->next;
	}
	wait(NULL);
	return (0);
}