/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:06:35 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 19:26:16 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char **arguments)
{
	int	i;

	i = 0;
	if (!arguments)
	{
		return ;
	}
	while (arguments[i] != NULL)
	{
		if (!arguments[i])
			return ;
		free(arguments[i]);
		i++;
	}
	free(arguments);
}
