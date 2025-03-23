#include "minishell.h"

int	func_pwd(t_word *prompt)
{
	char				*output;

	output = getcwd(NULL, 0);
	ft_putendl_fd(output, prompt->fd_out);
	free(output);
	return (1);
}
