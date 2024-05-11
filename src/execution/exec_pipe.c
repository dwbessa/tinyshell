/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:17:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/10 18:31:08 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command_pipe(t_word *prompt, int fd_aux, int *fd)
{
	char	**envp;
	char	**single_cmd;

	close(fd[0]);
	dup2(fd_aux, STDIN_FILENO);
	if (prompt->word != NULL)
		dup2(fd[1], STDOUT_FILENO);

	prompt->word = use_path(prompt->word, prompt->env);
	envp = env_to_matrix(prompt->env);
	single_cmd = transform_list(prompt);
	if ((execve(prompt->word, single_cmd, envp)) == -2)
	{
		printf("Error execve\n");
		exit(1);
	}
	close(fd[0]);
	//free_matrix(single_cmd);
	return (0);
}

int	pipe_operator (t_data *data)
{
	int	pid1;
	int	pid2;
	int	fd[2];
	int fd_aux;
	t_word	*prompt;

	prompt = data->prompt->head;
	(void)pid2;
	while (prompt)
	{
		if (pipe(fd) == -1)
			return (1);
		pid1 = fork();
		if (pid1 == 0)
			execute_command_pipe(prompt, fd_aux, fd);
		waitpid(pid1, NULL, 0);
		close(fd[1]);
		fd_aux = fd[0];
		prompt = prompt->next;
	}
	return (0);
}