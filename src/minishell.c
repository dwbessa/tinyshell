/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:21:59 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 13:10:42 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

unsigned int	g_exit_status;

int	main(void)
{
	//pid_t		mini_pid;
	char		*prompt;
	char		*pwd;
	char		**arguments;
	t_list		*env;

	//mini_pid = getpid();
	mini_clear();
	arguments = NULL;
	env = get_env_lst();
	ms_set_sighandle();
	while (42)
	{
		pwd = shell_name();
		prompt = readline(pwd);
		if (!prompt)
		{
			printf("exit\n");
			func_exit(arguments, prompt, pwd, env);
		}
		if (prompt && *prompt)
		{
			arguments = ft_split(prompt, ' ');
			add_history(prompt);
			handle_builtin(arguments, prompt, env, pwd);
			free_matrix(arguments);
		}
		free(prompt);
		free(pwd);
	}
	ft_lstclear(&env, free);
}

void	ms_set_sighandle(void)
{
	struct sigaction	sig;

	signal(SIGQUIT, SIG_IGN);
	sig.sa_handler = ms_sigint_handle;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGINT);
	sig.sa_flags = 0;
	sigaction(SIGINT, &sig, NULL);
	return ;
}

void	ms_sigint_handle(int signal)
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
		g_exit_status = 1;
	}
	return ;
}
