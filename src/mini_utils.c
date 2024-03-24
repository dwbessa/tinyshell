/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 17:17:35 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 12:50:42 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_clear(void)
{
	const char	*clear_screen_ansi;

	clear_screen_ansi = "\e[1;1H\e[2J";
	printf("%s", clear_screen_ansi);
	printf("\033[0;32mWelcome to Minishell\033[0m\n\n");
}

int	many_char(char *s, char c)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] != c)
			i++;
		else
			break ;
	}
	return (i);
}

char	*shell_name(void)
{
	extern char **environ;
	char		*output;
	char		*temp;
	char		*cwd;
	int			i;
	int			j;

	i = 0;
	output = "\033[1;32m";
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], "USER=", 5))
			output = ft_strjoin(output, environ[i] + 5);
		i++;
	}
	output = ft_strjoin_free(output, "@");
	i = 0;
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], "SESSION_MANAGER=local/", 22))
		{
			j = many_char(environ[i] + 22, ':');
			temp =  ft_substr(environ[i], 22, j);
			output = ft_strjoin_free(output, temp);
			free(temp);
		}
		i++;
	}
	output = ft_strjoin_free(output, "\033[0m:\033[1;34m");
	i = 0;
	while (environ[i])
	{
		if(!ft_strncmp(environ[i], "HOME=", 5))
		{
			j = ft_strlen(environ[i]) - 5;
			temp = ft_strdup(environ[i] + 5);
			i = 0;
			cwd = getcwd(NULL, 0);
			if (!ft_strncmp(cwd, temp, j))
			{
				output = ft_strjoin_free(output, "~");
				output = ft_strjoin_free(output, cwd + j);
			}
			else
				output = ft_strjoin_free(output, cwd);
			break ;
		}
		i++;
	}
	output = ft_strjoin_free(output, "\033[0m$ ");
	free(temp);
	free(cwd);
	return (output);
}
