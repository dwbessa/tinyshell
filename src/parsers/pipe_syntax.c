#include "minishell.h"

int	check_pipe_syntax(t_data *data)
{
	t_word	*prompt;

	prompt = data->prompt;
	if (prompt->flag == MS_PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	prompt = get_last_word(prompt);
	if (prompt->flag == MS_PIPE)
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		return (1);
	}
	return (0);
}
