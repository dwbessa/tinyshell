#include "minishell.h"

int	redir_out(t_word *prompt)
{
	t_word	*head;
	int		fd_out;

	head = prompt;
	while (head && head->flag != MS_WORD)
		head = head->next;
	while (prompt && prompt->flag != MS_PIPE)
	{
		if (prompt->flag == MS_REDIRECT_OUT)
		{
			fd_out = open(prompt->next->word, O_WRONLY
					| O_CREAT | O_TRUNC, 0644);
			if (fd_out == (-1))
			{
				perror("open");
				return (-1);
			}
			head->fd_out = fd_out;
		}
		prompt = prompt->next;
	}
	return (0);
}
