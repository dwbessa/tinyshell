/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:16:15 by aldantas          #+#    #+#             */
/*   Updated: 2024/03/21 16:19:55 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/minishell.h"

void	handle_builtin(char **argument, char *prompt, pid_t mini_pid)
{
	char	*output;
	int		length;

	if (ft_strncmp(argument[0], "pwd", 3) == 0)
	{
		length = 1024;
		output = malloc(sizeof(char) * length);
		getcwd(output, length);
		printf("%s\n", output);
	}
	else if (ft_strncmp(argument[0], "cd", 2) == 0)
	{
		if (!argument[1])
		{
			printf("Não funcionou, usar o path $HOME no código");
		}
		else
			chdir(argument[1]);
	}
	else if (ft_strncmp(argument[0], "echo", 4) == 0)
	{
		if (!argument[1])
			printf("\n");
		else if (ft_strncmp(argument[1], "-n", 2) == 0)
			printf("%s", prompt + 8);
		else
			printf("%s\n", prompt + 5);
	}
	else if (ft_strncmp(argument[0], "env", 3) == 0)
		output = command_env(argument, 1);
	else if (ft_strncmp(argument[0], "exit", 4) == 0)
		kill(mini_pid, SIGTERM);
	free(output);
}
