/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/05 12:32:45 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_clear(void)
{
	const char	*clear_screen_ansi;

	clear_screen_ansi = "\e[1;1H\e[2J";
	write(STDOUT_FILENO, clear_screen_ansi, 11);
}

void	handle_builtin(char **argument, char *prompt)
{
	char	*pwd;
	int		length;

	if (ft_strncmp(argument[0], "pwd", 3) == 0)
	{
		length = 1024;
		pwd = malloc(sizeof(char) * length);
		getcwd(pwd, length);
		printf("%s\n", pwd);
		free(pwd);
	}
	else if (ft_strncmp(argument[0], "cd", 2) == 0)
	{
		if (!argument[1])
		{
			printf("usar o path $HOME no código");
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
		command_env(argument, 1);
}

int	main(int argc, char **argv)
{
	char	*prompt;
	char	**arguments;

	mini_clear();
	printf("\033[0;32mWelcome to %s\033[0m\n", argv[0]);
	if (argc == 1)
	{
		while (1)
		{
			// print_env();
			prompt = readline("minishell> ");
			arguments = ft_split(prompt, ' ');
			if (prompt)
				add_history(prompt);
			handle_builtin(arguments, prompt);
			free(prompt);
		}
	}
}
