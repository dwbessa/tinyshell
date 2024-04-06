/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:44:40 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/06 12:46:50 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	func_pwd(void)
{
	char				*output;

	output = getcwd(NULL, 0);
	printf("%s\n", output);
	free(output);
	return (1);
}
