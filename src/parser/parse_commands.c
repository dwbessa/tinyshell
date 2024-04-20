/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:11:42 by aldantas          #+#    #+#             */
/*   Updated: 2024/04/20 01:42:42 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


int	count_commands(char *raw_command)
{
	int		i;
	int		nbr_cmd;
    
	i = 0;
	nbr_cmd = 1;
	while (raw_command[i])
	{
		if (raw_command[i] == '|')
		{
			nbr_cmd++;
		}
        i++;
	}
	return (nbr_cmd);
}
