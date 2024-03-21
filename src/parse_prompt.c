/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:11:52 by aldantas          #+#    #+#             */
/*   Updated: 2024/03/21 16:19:42 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/minishell.h"

int have_pipe(char *prompt)
{
    int i;

    i = 0;
    while(prompt[i])
        if (prompt[i++] == '|')
            return (1);
    return (0);
}