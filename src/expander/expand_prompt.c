/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:26:12 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 15:19:22 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_dollar_question(char *arg, unsigned int g_exit_status)
{
	free(arg);
	return (ft_itoa(g_exit_status));
}

static char	*handle_dollar(char *arg, t_list *env)
{
	t_list	*aux;
	int		len;

	aux = env;
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

char	**expand_prompt(char **arg, t_list *env)
{
	int					i;
	extern unsigned int	g_exit_status;

	i = 0;
	while (arg[i])
	{
		if (!ft_strncmp(arg[i], "$?", 3))
			arg[i] = handle_dollar_question(arg[i], g_exit_status);
		else if (!ft_strncmp(arg[i], "$", 1))
			arg[i] = handle_dollar(arg[i], env);
		else if (!ft_strncmp(arg[i], "~", 1))
			arg[i] = handle_tilde(arg[i], env);
		i++;
	}
	return (arg);
}
