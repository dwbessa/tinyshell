/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:18 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/04 22:34:31 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell.h"

int	command_clear(void)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *argv[] = {"/usr/bin/clear", NULL};
		execve(argv[0], argv, __environ);
		perror("clear failed");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	return (1);
}
