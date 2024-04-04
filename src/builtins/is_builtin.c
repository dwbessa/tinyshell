/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:10:01 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/04 10:34:33 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char **arg, char *prompt, t_list **env, char *pwd)
{
	int	builtin;

	builtin = 0;
	if (!ft_strncmp(arg[0], "pwd", 4))
		builtin = func_pwd();
	else if (!ft_strncmp(arg[0], "cd", 3))
		builtin = func_cd(arg, env);
	else if (!ft_strncmp(arg[0], "echo", 5))
		builtin = func_echo(arg, prompt);
	else if (!ft_strncmp(arg[0], "env", 4))
		builtin = func_env(env);
	else if (!ft_strncmp(arg[0], "exit", 5))
		func_exit(arg, prompt, env, pwd);
	else if (!ft_strncmp(arg[0], "export", 7))
		builtin = func_export(arg, *env);
	else if (!ft_strncmp(arg[0], "unset", 6))
		builtin = func_unset(arg, env);
	return (builtin);
}
