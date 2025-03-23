#include "minishell.h"

int	do_redir(t_word *prompt)
{
	if (!prompt)
		return (0);
	if (redir_in(prompt)
		|| redir_out(prompt)
		|| append(prompt))
		return (-1);
	return (0);
}
