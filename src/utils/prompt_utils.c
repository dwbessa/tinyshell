/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:17:35 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/21 08:55:15 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	many_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			i++;
		else
			break ;
	}
	return (i);
}

static char	*get_user(t_list *env, char *output)
{
	while (env)
	{
		if (!ft_strncmp((char *)(env->content), "USER=", 5))
		{
			output = ft_strjoin(output, (char *)(env->content + 5));
			break ;
		}
		env = env->next;
		if (!env)
			output = ft_strjoin(output, "marvin");
	}
	return (output);
}

static char	*get_session(t_list *env, char *output)
{
	char	*temp;
	int		j;

	while (env)
	{
		if (!ft_strncmp((char *)(env->content), "SESSION_MANAGER=local/", 22))
		{
			j = many_char((char *)(env->content + 22), ':');
			temp = ft_substr((char *)(env->content), 22, j);
			output = ft_strjoin_free(output, temp);
			free(temp);
			break ;
		}
		env = env->next;
		if (!env)
			output = ft_strjoin_free(output, "linux");
	}
	return (output);
}

static char	*get_pwd(t_list *env, char *output)
{
	int		j;
	char	*cwd;

	while (env)
	{
		if (!ft_strncmp((char *)(env->content), "HOME=", 5))
		{
			j = ft_strlen((char *)(env->content)) - 5;
			cwd = getcwd(NULL, 0);
			if (!ft_strncmp(cwd, (char *)(env->content + 5), j))
			{
				output = ft_strjoin_free(output, "~");
				output = ft_strjoin_free(output, cwd + j);
			}
			else
				output = ft_strjoin_free(output, cwd);
			break ;
		}
		env = env->next;
	}
	free(cwd);
	return (output);
}

char	*shell_name(t_list *env)
{
	t_list		*aux;
	char		*output;

	aux = env;
	output = "\001\033[1;32m\002";
	output = get_user(env, output);
	output = ft_strjoin_free(output, "@");
	env = aux;
	output = get_session(env, output);
	env = aux;
	output = ft_strjoin_free(output, "\001\033[0m:\033[1;34m\002");
	output = get_pwd(env, output);
	output = ft_strjoin_free(output, "\001\033[0m\002$ ");
	return (output);
}
