#include "minishell.h"

int	check_redir_syntax(t_data *data)
{
	t_word	*prompt;

	prompt = data->prompt;
	if ((prompt->flag == MS_REDIRECT_IN || prompt->flag == MS_REDIRECT_OUT
			|| prompt->flag == MS_APPEND))
	{
		ft_putstr_fd("minishell:  syntax error\n", 2);
		return (1);
	}
	prompt = get_last_word(prompt);
	if (prompt->flag == MS_REDIRECT_IN || prompt->flag == MS_REDIRECT_OUT
		|| prompt->flag == MS_APPEND || prompt->flag == MS_HEREDOC)
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		return (1);
	}
	return (0);
}
