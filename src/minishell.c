/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 12:40:39 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

unsigned int	g_exit_status;

int	main(void)
{
	char		*prompt;
	char		**arguments;
	char		*pwd;
	t_list		*env;

	arguments = NULL;
	env = get_env_lst();
	set_sighandle();
	while (42)
	{
		pwd = shell_name(env);
		prompt = readline(pwd);
		if (syntax_error(prompt))
			continue;
		if (prompt && *prompt)
			handle_prompt(prompt, arguments, pwd, &env);
		if (prompt == NULL || *prompt == EOF)
			func_exit(arguments, prompt, &env, pwd);
		free(prompt);
		free(pwd);
	}
	ft_lstclear(&env, free);
	return (0);
}

void	set_sighandle(void)
{
	struct sigaction	sig;

	signal(SIGQUIT, SIG_IGN);
	sig.sa_handler = sigint_handle;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGINT);
	sig.sa_flags = 0;
	sigaction(SIGINT, &sig, NULL);
	return ;
}

void	sigint_handle(int signal)
{
	extern unsigned int	g_exit_status;

	if (signal == SIGINT)
	{
		if (RL_ISSTATE(RL_STATE_READCMD))
			ioctl(STDIN_FILENO, TIOCSTI, "\n");
		else
			write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		g_exit_status = 130;
	}
	return ;
}
