/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 10:41:11 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 15:18:17 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_prompt(t_data *data)
{
	char	**split_arg;

	split_arg = ft_split(data->raw_cmd, ' ');
	add_history(data->raw_cmd);
	data->arg = expand_prompt(split_arg, data->env);
	if (!is_builtin(data))
		exec_command(data);
	free_matrix(data->arg);
}
