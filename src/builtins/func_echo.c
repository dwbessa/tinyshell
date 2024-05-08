/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwbessa <dwbessa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:45:24 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/05 17:43:58 by dwbessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	without_argument(t_word *prompt)
{
	while (prompt)
	{
		printf("%s", prompt->word);
		if (prompt->next)
			printf(" ");
		else
			printf("\n");
		prompt = prompt->next;
	}
}

int	func_echo(t_word *prompt)
{
	extern unsigned int	g_exit_status;
	t_word				*echo;

	echo = prompt->head;
	if (!echo->next)
	{
		printf("\n");
		return (1);
	}
	echo = echo->next;
	if (!ft_strncmp(echo->word, "-n", 3))
	{
		echo = echo->next;
		while (echo)
		{
			printf("%s", echo->word);
			if (echo->next)
				printf(" ");
			echo = echo->next;
		}
	}
	else
		without_argument(echo);
	g_exit_status = 0;
	return (1);
}
