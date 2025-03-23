#include "minishell.h"

t_word	*get_last_word(t_word *prompt)
{
	while (prompt->next != NULL)
		prompt = prompt->next;
	return (prompt);
}
