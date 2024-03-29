/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:57:03 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/29 11:48:04 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	func_exit(char **arg, char *prompt, t_list **envp, char *pwd)
{
	printf("exit\n");
	free_matrix(arg);
	free(prompt);
	free(pwd);
	ft_lstclear(envp, free);
	exit(EXIT_SUCCESS);
}
