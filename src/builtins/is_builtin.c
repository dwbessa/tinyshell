/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:10:01 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 15:30:40 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_data *data)
{
	int	builtin;

	builtin = 0;
	if (!ft_strncmp(data->arg[0], "pwd", 4))
		builtin = func_pwd();
	else if (!ft_strncmp(data->arg[0], "cd", 3))
		builtin = func_cd(data->arg, data->env);
	else if (!ft_strncmp(data->arg[0], "echo", 5))
		builtin = func_echo(data->arg);
	else if (!ft_strncmp(data->arg[0], "env", 4))
		builtin = func_env(data->env);
	else if (!ft_strncmp(data->arg[0], "exit", 5))
		func_exit(data);
	else if (!ft_strncmp(data->arg[0], "export", 7))
		builtin = func_export(data->arg, data->env);
	else if (!ft_strncmp(data->arg[0], "unset", 6))
		builtin = func_unset(data->arg, &data->env);
	return (builtin);
}
