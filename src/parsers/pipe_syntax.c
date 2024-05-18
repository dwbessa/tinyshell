/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_syntax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:40:23 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/18 00:33:24 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe_syntax(t_data *data)
{
	t_word	*prompt;

	prompt = data->prompt;
	if (prompt->flag == MS_PIPE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n", 2);
		return (1);
	}
	prompt = get_last_word(prompt);
	if (prompt->flag == MS_PIPE)
	{
		ft_putstr_fd("minishell: syntax error\n", 2);
		return (1);
	}
	return (0);
}
