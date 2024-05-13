/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 00:52:48 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/13 01:23:54 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "minishell.h"

int	do_redir(t_word *prompt)
{
	if (!prompt)
		return (0);
	if (redir_in(prompt))
		return (-1);
	return (0);
}

int redir_in(t_word *prompt) {
    t_word *head = prompt;
    int fd_in;
    
    while (head && head->flag != MS_WORD)
        head = head->next;
    while (prompt && prompt->flag != MS_PIPE) 
    {
        if (prompt->flag == MS_REDIRECT_IN) 
        {
            if (access(prompt->next->word, F_OK | R_OK) != -1) {
                fd_in = open(prompt->next->word, O_RDONLY);
                if (fd_in == -1) {
                    perror("open");
                    return -1;
                }
                head->fd_in = fd_in;
            } else {
                printf("Error: No such file as '%s'\n", prompt->next->word);
                return -1;
            }
        }
        prompt = prompt->next;
    }
    return 0; 
}