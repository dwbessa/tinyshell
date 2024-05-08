/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwbessa <dwbessa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:06:35 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/05 08:29:49 by dwbessa          ###   ########.fr       */
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
