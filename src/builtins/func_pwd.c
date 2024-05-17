/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:44:40 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/17 16:24:33 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	func_pwd(t_word *prompt)
{
	char				*output;

	output = getcwd(NULL, 0);
	ft_putendl_fd(output, prompt->fd_out);
	free(output);
	return (1);
}
