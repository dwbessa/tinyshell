/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:06:35 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/18 02:25:38 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char **arguments)
{
	int	i;

	i = 0;
	if (!arguments)
		return ;
	while (arguments[i] != NULL)
	{
		if (!arguments[i])
			return ;
		free(arguments[i]);
		i++;
	}
	free(arguments);
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
