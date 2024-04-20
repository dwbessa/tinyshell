/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:41:11 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/20 01:44:50 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_prompt(t_data *data)
{
	char	**split_arg;
	
	data->nbr_of_cmds = count_commands(data->raw_cmd);
	split_arg = ft_split(data->raw_cmd, ' ');
	add_history(data->raw_cmd);
	data->arg = expand_prompt(split_arg, data->env);
	if (data->nbr_of_cmds == 1)
	{
		//ft_init_data_one_cmd(data);
		one_command(data);
	}
	else if (data->nbr_of_cmds > 1)
	{
		init_data_multiple_cmds(data);
		multiple_commands(data);
	}
	free_matrix(data->arg);
}
