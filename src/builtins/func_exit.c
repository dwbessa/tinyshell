/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwbessa <dwbessa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:57:03 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/05 12:57:47 by dwbessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_exit(t_data *data)
{
	extern unsigned int	g_exit_status;

	printf("minishell: exit\n");
	if (data->raw_cmd == NULL || *data->raw_cmd == EOF)
	{
		free(data->pwd);
		ft_lstclear(&data->env, free);
		exit(EXIT_SUCCESS);
	}
	free_matrix(data->arg);
	free(data->raw_cmd);
	free(data->pwd);
	ft_lstclear(&data->env, free);
	rl_clear_history();
	g_exit_status = 0;
	exit(g_exit_status);
}
