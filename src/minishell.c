/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/02 11:22:04 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_clear(void)
{
	const char	*clear_screen_ansi;

	clear_screen_ansi = "\e[1;1H\e[2J";
	write(STDOUT_FILENO, clear_screen_ansi, 11);
}

void	interpret_prompt(char **argument, char *prompt)
{
	char	*pwd;
	int		length;
	int		i;
	int		y;
	char	*new_path;

	if (strncmp(argument[0], "pwd", 3) == 0)
	{
		length = 1024;
		pwd = malloc(sizeof(char) * length);
		getcwd(pwd, length);
		printf("%s\n", pwd);
		free(pwd);
	}
	else if (strncmp(argument[0], "cd", 2) == 0)
	{
		i = 0;
		y = 0;
		if (!argument[1])
		{
			length = 1024;
			pwd = malloc(sizeof(char) * length);
			getcwd(pwd, length);
			while (i < 4)
			{
				if (pwd[y] == '/')
					i++;
				y++;
			}
			new_path = ft_substr(pwd, 0, y);
			chdir(new_path);
			free(pwd);
			free(new_path);
		}
		else
			chdir(argument[1]);
	}
	else if (strncmp(argument[0], "echo", 4) == 0)
	{
		if (!argument[1])
			printf("\n");
		else if (strncmp(argument[1], "-n", 2) == 0)
			printf("%s", prompt + 8);
		else
			printf("%s\n", prompt + 5);
	}
}

int	main(int argc, char **argv)
{
	char	*prompt;
	char	**arguments;

	mini_clear();
	printf("Welcome to %s\n", argv[0]);
	if (argc == 1)
	{
		while (1)
		{
			prompt = readline("minishell> ");
			arguments = ft_split(prompt, ' ');
			if (prompt)
				add_history(prompt);
			interpret_prompt(arguments, prompt);
			free(prompt);
		}
	}
}
