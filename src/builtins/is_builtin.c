/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwbessa <dwbessa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 10:10:01 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/05 17:59:26 by dwbessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_data *data)
{
	int		builtin;
	t_word	*prompt;

	prompt = data->prompt->head;
	builtin = 0;
	if (!ft_strncmp(prompt->word, "pwd", 4))
		builtin = func_pwd();
	else if (!ft_strncmp(prompt->word, "cd", 3))
		builtin = func_cd(data->prompt);
	else if (!ft_strncmp(prompt->word, "echo", 5))
		builtin = func_echo(data->prompt);
	else if (!ft_strncmp(prompt->word, "env", 4))
		builtin = func_env(prompt->env);
	else if (!ft_strncmp(prompt->word, "exit", 5))
		func_exit(data);
	else if (!ft_strncmp(prompt->word, "export", 7))
		builtin = func_export(prompt, prompt->env);
	else if (!ft_strncmp(prompt->word, "unset", 6))
		builtin = func_unset(prompt, &prompt->env);
	return (builtin);
}
