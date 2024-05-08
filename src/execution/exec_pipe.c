/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:17:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/08 17:13:29 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_command_pipe(int i, char **args, t_data *data)
{
    char    *path;
	char	**envp;
	char	**single_cmd;

    path = use_path(args[i], data->env);
	envp = env_to_matrix(data->env);
	single_cmd = ft_split_charset(data->raw_cmd, "| ");
	single_cmd[i + 1] = NULL;
	if ((execve(path, single_cmd, envp)) == -2)
	{
		printf("Error execve\n");
		exit(1);
	}
    return (0);
}

int	pipe_operator(int fd[], char **args, t_data *data)
{
	int	i;
	int	pid1;
	int	pid2;

    (void)pid2;
	i = 0;
	if (pipe(fd) == -1)
		return (1);
	while (args[i])
	{
		pid1 = fork();
		if (pid1 < 0)
			return (2);
		
		if (pid1 == 0)
		{
            // args[i] = NULL;
			// printf("processo filho");
			// child process 1 (ping)
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);
			close(fd[1]);
			execute_command_pipe(0 ,args, data);
		}
		else
			waitpid(pid1, NULL, 0);
		i++;
	}
    return (0);
}