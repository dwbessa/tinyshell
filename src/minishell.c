/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/06 10:03:39 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t				mini_pid;
	char				*prompt;
	char				**arguments;

	mini_pid = getpid();
	mini_clear(argv[0]);
	if (argc == 1)
	{
		while (42)
		{
			prompt = readline("minishell> ");
			while (!prompt)
			{
				free(prompt);
				prompt = readline("minishell > ");
			}
			arguments = ft_split(prompt, ' ');
			add_history(prompt);
			handle_builtin(arguments, prompt, mini_pid, envp);
			free_matrix(arguments);
			free(prompt);
		}
	}
}
