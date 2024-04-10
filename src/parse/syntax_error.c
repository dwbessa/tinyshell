/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:02:47 by aldantas          #+#    #+#             */
/*   Updated: 2024/04/10 14:18:43 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	syntax_error(char *prompt)
{
	if (check_valid_quotes(prompt) == 0)
		return (write(2, "quote>\n", 8));
	if (ft_strchr(prompt, '|') && check_pipe_syntax(prompt))
		return (1);
	if ((ft_strchr(prompt, '>') || ft_strchr(prompt, '<'))
		&& check_redir_syntax(prompt))
		return (1);
	return (0);
}

int	check_valid_quotes(char *str)
{
	int		i;
	int		s_quotes;
	int		d_quotes;
	
	i = -1;
	s_quotes = 0;
	d_quotes = 0;
	if (ft_strlen(str) == 0)
		return (1);
	while (str[++i])
	{
		if (str[i] == '\'')
			s_quotes++;
		else if (str[i] == '\"')
			d_quotes++;
	}
	if ((d_quotes % 2 == 0 && s_quotes == 0)
		|| (s_quotes % 2 == 0 && d_quotes == 0)
		|| (d_quotes % 2 == 0 && s_quotes % 2 == 0))
		return (1);
	else
		return (0);
}

int	check_pipe_syntax(char *prompt)
{
	if (prompt[0] == '|')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	if (ft_strlen(prompt) - 1 == '|')
	{
		ft_putstr_fd("pipe>\n", 2);
		return (1);
	}
	return (0);
}

int	check_redir_syntax(char *prompt)
{
	if (prompt[0] == '<' || prompt[0] == '>')
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	if (ft_strlen(prompt) - 1 == '<' || ft_strlen(prompt) -1 == '>')
	{
		ft_putstr_fd("pipe>\n", 2);
		return (1);
	}
	return (0);
}