/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:18 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/21 16:19:44 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/minishell.h"

void	handle_pid_zero(char **argument, int *pipefd)
{
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 failed");
		exit(EXIT_FAILURE);
	}
	close(pipefd[1]);
	if (execve("/usr/bin/env", argument, __environ) == -1)
	{
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

char	*handle_pid(int *pipefd, int fd)
{
	char	*line;
	char	*buffer;

	close(pipefd[1]);
	line = get_next_line(pipefd[0]);
	buffer = ft_strdup(line);
	while (line)
	{
		ft_putstr_fd(line, fd);
		buffer = ft_strjoin(buffer, line);
		free(line);
		line = get_next_line(pipefd[0]);
	}
	free(line);
	close(pipefd[0]);
	return (buffer);
}

char	*command_env(char **argument, int fd)
{
	pid_t	pid;
	char	*all_env;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe failed");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		handle_pid_zero(argument, pipefd);
	all_env = handle_pid(pipefd, fd);
	if (all_env == NULL)
	{
		perror("handle_pid failed");
		exit(EXIT_FAILURE);
	}
	return (all_env);
}

void	print_env(void)
{
	char	*env_lines;
	char	**args;

	args = (char *[]){"env", NULL};
	env_lines = command_env(args, -1);
	printf("%s\n", env_lines);
}
