/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 01:21:59 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/18 01:31:25 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_quotes(t_data *data)
{
	if (!quote_number(data))
	{
		quote_error();
		return (-1);
	}
	return (0);
}
