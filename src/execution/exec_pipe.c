/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:17:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/08 19:43:18 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	theres_pipe(t_word *prompt)
{
	t_word	*aux;

	aux = prompt;
	while (prompt)
	{
		if (prompt->flag == MS_PIPE)
			return (1);
		prompt = prompt->next;
	}
	prompt = aux;
	return (0);
}

int	execute_command_pipe(t_word *prompt, int *fd)
{
	char	**envp;
	char	**single_cmd;
	
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
    prompt->word = use_path(prompt->word, prompt->env);
	envp = env_to_matrix(prompt->env);
	single_cmd = transform_list(prompt);
	if ((execve(prompt->word, single_cmd, envp)) == -2)
	{
		printf("Error execve\n");
		exit(1);
	}
	//free_matrix(single_cmd);
    return (0);
}

int	pipe_operator (t_data *data)
{
	int	pid1;
	int	pid2;
	int	fd[2];
	t_word	*prompt;

	prompt = data->prompt->head;
    (void)pid2;
	while (prompt)
	{
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 == 0)
			execute_command_pipe(prompt, fd);
		else
		{
			waitpid(pid1, NULL, 0);
			close(fd[1]);
		}

		prompt = prompt->next;
	}
    return (0);
}