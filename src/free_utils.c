/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwbessa <dwbessa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:06:35 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/21 16:32:44 by dwbessa          ###   ########.fr       */
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
