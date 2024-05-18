/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:56:49 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/15 02:32:17 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	append(t_word *prompt)
{
	t_word	*head;
	int		fd_out;

	head = prompt;
	while (head && head->flag != MS_WORD)
		head = head->next;
	while (prompt && prompt->flag != MS_PIPE)
	{
		if (prompt->flag == MS_APPEND)
		{
			fd_out = open(prompt->next->word, O_WRONLY
					| O_APPEND | O_CREAT, 0644);
			if (fd_out == (-1))
			{
				perror("open");
				return (-1);
			}
			head->fd_out = fd_out;
		}
		prompt = prompt->next;
	}
	return (0);
}
