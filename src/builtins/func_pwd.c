/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:44:40 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 13:20:57 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_pwd(void)
{
	extern unsigned int	g_exit_status;
	char	*output;

	output = getcwd(NULL, 0);
	printf("%s\n", output);
	g_exit_status = 0;
	free(output);
}
