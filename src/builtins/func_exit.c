/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:57:03 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 15:38:06 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_exit(t_data *data)
{
	extern unsigned int	g_exit_status;

	printf("minishell: exit\n");
	free_matrix(data->arg);
	free(data->raw_cmd);
	free(data->pwd);
	ft_lstclear(&data->env, free);
	g_exit_status = 0;
	exit(EXIT_SUCCESS);
}
