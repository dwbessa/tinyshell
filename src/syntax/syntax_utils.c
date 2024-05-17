/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 02:08:22 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/17 16:16:49 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_word	*get_last_word(t_word *prompt)
{
	while (prompt->next != NULL)
		prompt = prompt->next;
	return (prompt);
}
