#include "minishell.h"

void	unsetting_env(t_list *prev, t_list *curr, char *arg, t_list **env)
{
	t_list		*next;
	char		*content;
	int			len;

	while (curr)
	{
		next = curr->next;
		content = (char *)curr->content;
		len = ft_strlen(arg);
		if (!ft_strncmp(arg, curr->content, len)
			&& (content[len] == '=' || content[len] == '\0'))
		{
			if (prev)
				prev->next = curr->next;
			else
				*env = curr->next;
			ft_lstdelone(curr, free);
			break ;
		}
		prev = curr;
		curr = next;
	}
}

int	func_unset(t_word *prompt, t_list **env)
{
	extern unsigned int	g_exit_status;
	t_list				*prev;
	t_list				*curr;
	t_word				*unset;

	unset = prompt->head;
	if (!unset->next)
	{
		g_exit_status = 0;
		return (1);
	}
	unset = unset->next;
	while (unset)
	{
		prev = NULL;
		curr = *env;
		unsetting_env(prev, curr, unset->word, env);
		unset = unset->next;
	}
	g_exit_status = 0;
	return (1);
}
