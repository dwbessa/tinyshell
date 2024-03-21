/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/21 15:55:41 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

void	mini_clear(void)
{
	const char	*clear_screen_ansi;

	clear_screen_ansi = "\e[1;1H\e[2J";
	write(STDOUT_FILENO, clear_screen_ansi, 11);
}

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

static char	*get_input(void)
{
	char	*input;
	char	*trimmed_input;

	input = readline("minishell> ");
	trimmed_input = ft_strtrim(input, " \t");
	return (trimmed_input);
}

void	exec_cmd(char *prompt, pid_t mini_pid)
{
	char				**arguments;

	arguments = ft_split(prompt, ' ');
	handle_builtin(arguments, prompt, mini_pid);
}

int	main(int argc, char **argv)
{
	pid_t				mini_pid;
	char				*prompt;

	mini_pid = getpid();
	mini_clear();
	if (argv && argc == 1)
	{
		while (42)
		{
			prompt = get_input();
			add_history(prompt);
			if(!prompt[0])
			{
				//free(prompt);
				continue ;
			}
			/*criar func para checar se o prompt é valido*/
			exec_cmd(prompt, mini_pid);
		}
	}
}

