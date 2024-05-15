/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:57:10 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/15 02:34:43 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	do_redir(t_word *prompt)
{
	if (!prompt)
		return (0);
	if (redir_in(prompt)
		|| redir_out(prompt)
		|| append(prompt))
		return (-1);
	return (0);
}
