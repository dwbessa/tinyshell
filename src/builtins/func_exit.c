#include "minishell.h"

void	func_exit(t_data *data)
{
	extern unsigned int	g_exit_status;

	printf("minishell: exit\n");
	if (data->raw_cmd == NULL || *data->raw_cmd == EOF)
	{
		free(data->pwd);
		ft_lstclear(&data->env, free);
		exit(EXIT_SUCCESS);
	}
	free_prompt(data->prompt);
	free(data->raw_cmd);
	free(data->pwd);
	ft_lstclear(&data->env, free);
	rl_clear_history();
	g_exit_status = 0;
	exit(g_exit_status);
}
