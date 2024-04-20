/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:45:24 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/19 23:33:50 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	without_argument(char **argument)
{
	int	i;

	i = 1;
	while (argument[i])
	{
		printf("%s", argument[i]);
		if (argument[i + 1] != NULL)
			printf(" ");
		else
			printf("\n");
		i++;
	}
}

int	func_echo(char **argument)
{
	extern unsigned int	g_exit_status;
	int					i;

	if (!argument[1])
		printf("\n");
	else if (ft_strncmp(argument[1], "-n", 2) == 0)
	{
		i = 2;
		while (argument[i])
		{
			printf("%s", argument[i]);
			if (argument[i + 1] != NULL)
				printf(" ");
			i++;
		}
	}
	else
		without_argument(argument);
	g_exit_status = 0;
	return (1);
}
