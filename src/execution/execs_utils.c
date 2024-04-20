/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:28:20 by aldantas          #+#    #+#             */
/*   Updated: 2024/04/20 01:42:09 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_generic_multiple(t_data *data, char **splitted_cmd)
{
	char	*path;

	path = transform_arg(splitted_cmd[0], data->env);
	printf("%s", path);
	if (!path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(splitted_cmd[0], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		exit(1);
	}
	execve(path, splitted_cmd, data->envp);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(splitted_cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit (127);
}

void	exec_multiple(t_data *data, char *raw_cmd)
{
	char	**splitted_cmd;

	splitted_cmd = ft_split(raw_cmd, ' ');
	if (is_builtin(data))
	{
		exit (0);
	}
	else if (!raw_cmd[0])
		exit(0);
	else
		exec_generic_multiple(data, splitted_cmd);
}