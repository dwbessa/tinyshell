/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:34:11 by dwbessa           #+#    #+#             */
/*   Updated: 2024/05/08 18:59:44 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*ms_lstnew(void *word)
{
	t_word	*new;

	new = (t_word *)malloc(sizeof(t_word));
	if (!new)
		return (NULL);
	new->word = word;
	new->flag = 0;
	new->pid = 0;
	new->fd_in = 0;
	new->fd_out = 1;
	new->ret = -1;
	new->next = NULL;
	return (new);
}

void	ms_lstadd_back(t_word **lst, t_word *new)
{
	t_word	*last_node;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last_node = *lst;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new;
	}
	return ;
}

t_list	*ms_create_env_lst(void)
{
	extern char	**environ;
	t_list		*head;
	t_list		*node;
	int			i;

	i = 0;
	head = NULL;
	while (environ[i])
	{
		node = ft_lstnew(ft_strdup(environ[i]));
		if (!node)
		{
			ft_lstclear(&node, free);
			return (NULL);
		}
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}

char	**transform_list(t_word *prompt)
{
	int		i;
	t_word	*aux;
	char	**matrix;

	i = 0;
	aux = prompt->head;
	while (prompt && prompt->flag != MS_PIPE)
	{
		i++;
		prompt = prompt->next;
	}
	prompt = aux->head;
	matrix = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (prompt && prompt->flag != MS_PIPE)
	{
		matrix[i] = ft_strdup(prompt->word);
		i++;
		prompt = prompt->next;
	}
	matrix[i] = NULL;
	return (matrix);
}
