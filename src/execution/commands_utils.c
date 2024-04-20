/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:01:23 by aldantas          #+#    #+#             */
/*   Updated: 2024/04/19 19:45:10 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	**separate_cmds(t_data *data)
{
	//int		i;
	//int		len;
	char	**separate_cmds;

	//i = -1;
	separate_cmds = ft_split(data->raw_cmd, '|');
	// len = ft_array_size(separate_cmds);
	// while (separate_cmds[++i])
	// 	if (ft_check_pipe(separate_cmds, i, len))
	// 		return (NULL);
	return (separate_cmds);
}

void	init_data_multiple_cmds(t_data *data)
{
	data->mul_cmds = separate_cmds(data);
	data->in_files = NULL;
	data->out_files = NULL;
	data->infile = NULL;
	data->outfile = NULL;
	data->in_files = NULL;
	data->out_files = NULL;

}

static void	parent(t_data*data)
{
	dup2(data->pipefd[0], STDIN_FILENO);
	close(data->pipefd[0]);
	close(data->pipefd[1]);
}

void	child_process(t_data *data, int nbr)
{
	if (nbr != data->nbr_of_cmds - 1)
		dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[1]);
	close(data->pipefd[0]);
}

static void	wait_childs(t_data *data)
{
	int	nbr;
	int	pid;
	int	status;

	nbr = data->nbr_of_cmds;
	if (nbr == 1)
		return ;
	while (nbr--)
	{
		pid = waitpid(-1, &status, 0);
		if (nbr == 0 && WIFSIGNALED(status))
		{
			status += 128;
			// catch_signal(data, status, 0);
		}
		else if (pid == data->pid)
			if (WIFEXITED(status))
				data->status = WEXITSTATUS(status);
	}
}

int	multiple_commands(t_data *data)
{
	int	nbr;

	nbr = -1;
	if (data->mul_cmds == NULL)
		return (0);
	while (++nbr < data->nbr_of_cmds)
	{
		pipe(data->pipefd);
		signal(SIGINT, SIG_IGN);
		data->pid = fork();
		if (data->pid < 0)
		{
			close(data->pipefd[1]);
			close(data->pipefd[0]);
			exit (0);
		}
		if (data->pid == 0)
		{
			child_process(data, nbr);
			exec_multiple(data, data->mul_cmds[nbr]);
		}
		parent(data);
	}
	wait_childs(data);
	return (0);
}