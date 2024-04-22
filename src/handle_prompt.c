/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwbessa <dwbessa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:41:11 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/21 17:17:42 by dwbessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_prompt(t_data *data)
{
	char	**split_arg;
	t_word	*prompt;

	split_arg = ft_split(data->raw_cmd, ' ');
	add_history(data->raw_cmd);
	data->arg = expand_prompt(split_arg, data->env);
	prompt = tokenizer(data);
	if (!is_builtin(data))
		exec_command(data);
	print_word(prompt);
	free_matrix(data->arg);
	free_prompt(prompt);
}

t_word	*tokenizer(t_data *data)
{
	t_word	*prompt;
	int		last_flag;
	int		i;

	prompt = ms_lstnew(ft_strdup(*data->arg));
	prompt->head = prompt;
	last_flag = 0;
	i = 0;
	while (data->arg[i])
	{
		prompt->flag = give_token(prompt->word, last_flag);
		last_flag = prompt->flag;
		i++;
		if (data->arg[i])
		{
			prompt->next = ms_lstnew(ft_strdup(data->arg[i]));
			prompt->next->head = prompt->head;
			prompt = prompt->next;
		}
	}
	prompt->next = NULL;
	prompt = prompt->head;
	return (prompt);
}

unsigned int	give_token(char *word, int last_flag)
{
	if (!word)
		return (-1);
	if (!ft_strncmp("|", word, 2))
		return (MS_PIPE);
	else if (!ft_strncmp("<", word, 2))
		return (MS_REDIRECT_IN);
	else if (!ft_strncmp(">", word, 2))
		return (MS_REDIRECT_OUT);
	else if (!ft_strncmp(">>", word, 3))
		return (MS_APPEND);
	else if (!ft_strncmp("<<", word, 3))
		return (MS_HEREDOC);
	else if (last_flag == MS_REDIRECT_OUT || last_flag == MS_REDIRECT_IN
		|| last_flag == MS_HEREDOC || last_flag == MS_APPEND)
		return (MS_REDIRECT_FILE);
	return (MS_WORD);
}

void	print_word(t_word *prompt)
{
	t_word	*print;

	print = prompt->head;
	while (print != NULL)
	{
		printf("WORD = %s\nTOKEN = %d\n", print->word, print->flag);
		print = print->next;
	}
}

void	free_prompt(t_word *prompt)
{
	t_word	*tmp;

	while (prompt != NULL)
	{
		tmp = prompt;
		prompt = prompt->next;
		free(tmp->word);
		free(tmp);
	}
}

t_word	*ms_lstnew(char *word)
{
	t_word	*new;

	new = (t_word *)malloc(sizeof(t_word));
	if (!new)
		return (NULL);
	new->word = word;
	new->next = NULL;
	return (new);
}
