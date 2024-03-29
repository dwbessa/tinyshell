/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:10:01 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/29 11:49:56 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_builtin(char **arg, char *prompt, t_list **env, char *pwd)
{
	if (!ft_strncmp(arg[0], "pwd", 4))
		func_pwd();
	else if (!ft_strncmp(arg[0], "cd", 3))
		func_cd(arg, env);
	else if (!ft_strncmp(arg[0], "echo", 5))
		func_echo(arg, prompt);
	else if (!ft_strncmp(arg[0], "env", 4))
		func_env(env);
	else if (!ft_strncmp(arg[0], "exit", 5))
		func_exit(arg, prompt, env, pwd);
	else if (!ft_strncmp(arg[0], "export", 7))
		func_export(arg, *env);
}
