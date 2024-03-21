/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/21 16:43:42 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/minishell.h"

void	mini_clear(void)
{
	const char	*clear_screen_ansi;

	clear_screen_ansi = "\e[1;1H\e[2J";
	write(STDOUT_FILENO, clear_screen_ansi, 11);
}

static char	*get_input(void)
{
	char	*input;
	char	*trimmed_input;

	input = readline("minishell> ");
	trimmed_input = ft_strtrim(input, " \t");
	return (trimmed_input);
}

void	exec_cmd(char *prompt, char **envp, pid_t mini_pid)
{
	char				**arguments;
	(void)envp;
	arguments = ft_split(prompt, ' ');
	// if (have_pipe(prompt))
	// 	exec_pipe(5, arguments, envp);
	// else
	handle_builtin(arguments, prompt, mini_pid);
}

int	main(int argc, char **argv, char **envp)
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
				free(prompt);
				continue ;
			}
			/*criar func para checar se o prompt é valido*/
			exec_cmd(prompt, envp, mini_pid);
		}
	}
}

