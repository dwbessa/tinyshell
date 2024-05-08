/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:17:45 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/08 12:48:42 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	execute_command_pipe(int i, char **args, t_data *data)
{
    char    *path;

    path = use_path(args[i], data->env);
	if ((execve(path, args, NULL)) == -2)
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
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	while (args[i])
	{
		if (ft_strncmp(args[i], "|", ft_strlen(args[i])) == 0)
		{
			if (pid1 == 0)
			{
                args[i] = NULL;
				// printf("processo filho");
				// child process 1 (ping)
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				execute_command_pipe(0 ,args, data);
			}
			else
			{
				// printf("processo pai");
				dup2(fd[0], STDIN_FILENO);
				close(fd[0]);
				close(fd[1]);
				execute_command_pipe(2, args, data);
				waitpid(pid1, NULL, 0);
			}
		}
		i++;
	}
    return (0);
}