#include "minishell.h"

int	syntax_errors(t_data *data)
{
	if (check_pipe_syntax(data) || check_redir_syntax(data))
		return (1);
	return (0);
}
