/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:10:01 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/15 10:10:03 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_echo(char **argument, char *prompt)
{
	if (!argument[1])
		printf("\n");
	else if (ft_strncmp(argument[1], "-n", 2) == 0)
		printf("%s", prompt + 8);
	else
		printf("%s\n", prompt + 5);
}

void	func_pwd(void)
{
	char	*output;
	int		len;

	length = 1024;
	output = malloc(sizeof(char) * len);
	getcwd(output, len);
	printf("%s\n", output);
}

void	func_cd(char **argument, char **envp)
{
	int	i;

	i = 0;
	if (!argument[1] || ft_strncmp(argument[1], "~", 2) == 0)
	{
		while (envp[i])
		{
			if (ft_strncmp(envp[i], "HOME", 4) == 0)
			{
				chdir(envp[i] + 5);
			}
			i++;
		}
	}
	else
		chdir(argument[1]);
}

void	handle_builtin(char **arg, char *prompt, pid_t pid, char **envp)
{
	char	*output;
	int		length;
	int		i;

	if (ft_strncmp(argument[0], "pwd", 3) == 0)
		func_pwd();
	else if (ft_strncmp(argument[0], "cd", 2) == 0)
		func_cd(argument, envp);
	else if (ft_strncmp(argument[0], "echo", 4) == 0)
		func_echo(argument, prompt);
	else if (ft_strncmp(argument[0], "env", 3) == 0)
	{
		i = 0;
		while (envp[i])
		{
			printf("%s\n", envp[i]);
			i++;
		}
	}
	else if (ft_strncmp(argument[0], "exit", 4) == 0)
		kill(mini_pid, SIGTERM);
}
