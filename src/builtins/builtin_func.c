/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:10:01 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 13:20:36 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_builtin(char **arg, char *prompt, t_list *env, char *pwd)
{
	if (ft_strncmp(arg[0], "pwd", 3) == 0)
		func_pwd();
	else if (ft_strncmp(arg[0], "cd", 2) == 0)
		func_cd(arg, env);
	else if (ft_strncmp(arg[0], "echo", 4) == 0)
		func_echo(arg, prompt);
	else if (ft_strncmp(arg[0], "env", 3) == 0)
		func_env(env);
	else if (ft_strncmp(arg[0], "exit", 4) == 0)
		func_exit(arg, prompt, pwd, env);
}
