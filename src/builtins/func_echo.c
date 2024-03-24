/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:45:24 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 10:45:33 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_echo(char **argument, char *prompt)
{
	if (!argument[1])
		printf("\n");
	else if (ft_strncmp(argument[1], "-n", 2) == 0)
		printf("%s", prompt + 8);
	else
		printf("%s\n", prompt + 5);
}
