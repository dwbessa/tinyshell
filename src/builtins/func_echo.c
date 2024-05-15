/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:45:24 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/15 19:54:20 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

void	without_argument(t_word *node, t_word *prompt)
{
	while (node && node->flag == MS_WORD)
	{
		ft_putstr_fd(node->word, prompt->fd_out);
		if (node->next && node->flag == MS_WORD)
			ft_putchar_fd(' ', prompt->fd_out);
		else
			ft_putchar_fd('\n', prompt->fd_out);
		node = node->next;
	}
}

int	func_echo(t_word *prompt)
{
	extern unsigned int	g_exit_status;
	t_word				*node;

	node = prompt->head;
	if (!node->next)
	{
		printf("\n");
		return (1);
	}
	node = node->next;
	if (!ft_strncmp(node->word, "-n", 2))
	{
		node = node->next;
		while (node && node->flag == MS_WORD)
		{
			ft_putstr_fd(node->word, prompt->fd_out);
			if (node->next && node->flag == MS_WORD)
				ft_putchar_fd(' ', prompt->fd_out);
			node = node->next;
		}
	}
	else
		without_argument(node, prompt);
	g_exit_status = 0;
	return (1);
}
