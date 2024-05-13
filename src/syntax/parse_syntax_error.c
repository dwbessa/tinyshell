/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 01:45:26 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/13 11:48:30 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int syntax_errors(t_data *data)
{
    if (!quote_number(data))
    {
		quote_error();
        return (1);
    }
    if (check_pipe_syntax(data))
    {
	    return (1);
    }
    return (0);
}