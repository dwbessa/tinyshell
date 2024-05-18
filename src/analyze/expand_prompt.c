/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:26:12 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/18 00:32:58 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quotes(char *arg)
{
	char	*new;

	if (*arg == '\"')
	{
		new = ft_strtrim(arg, "\"");
		free(arg);
		arg = new;
	}
	else if (*arg == '\'')
	{
		new = ft_strtrim(arg, "\'");
		free(arg);
		arg = new;
	}
	return (arg);
}

static char	*handle_dollar_question(char *arg, unsigned int g_exit_status)
{
	free(arg);
	return (ft_itoa(g_exit_status));
}

static char	*handle_dollar(char *arg, t_list *env)
{
	t_list	*aux;
	char	*new;
	int		len;

	aux = env;
	if (*arg == '\"')
	{
		new = ft_strtrim(arg, "\"");
		free(arg);
		arg = new;
	}
	while (aux)
	{
		len = ft_strlen(arg + 1);
		if (!ft_strncmp(arg + 1, aux->content, len))
		{
			free(arg);
			return (ft_strdup(ft_strchr(aux->content, '=') + 1));
		}
		aux = aux->next;
	}
	return (arg);
}

static char	*handle_tilde(char *arg, t_list *env)
{
	t_list	*aux;
	char	*temp;

	aux = env;
	while (aux)
	{
		if (!ft_strncmp(aux->content, "HOME=", 5))
		{
			temp = ft_strjoin(aux->content + 5, arg + 1);
			free(arg);
			arg = temp;
			break ;
		}
		aux = aux->next;
	}
	return (arg);
}

void	expand_prompt(t_word **prompt)
{
	t_word				*expand;
	extern unsigned int	g_exit_status;

	expand = *prompt;
	while (expand)
	{
		if (*expand->word != '\'' && (!ft_strncmp(expand->word, "$?", 3)
				|| !ft_strncmp(expand->word, "\"$?\"", 5)))
			expand->word = handle_dollar_question(expand->word, g_exit_status);
		else if (*expand->word != '\'' && (!ft_strncmp(expand->word, "$", 1)
				|| !ft_strncmp(expand->word, "\"$", 2)))
			expand->word = handle_dollar(expand->word, expand->env);
		else if (!ft_strncmp(expand->word, "~", 1) && (*expand->word != '\''
				|| *expand->word != '\"'))
			expand->word = handle_tilde(expand->word, expand->env);
		else if ((*expand->word != '\'' || *expand->word != '\"'))
			expand->word = remove_quotes(expand->word);
		expand = expand->next;
	}
}
