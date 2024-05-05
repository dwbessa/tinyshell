/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwbessa <dwbessa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:05:16 by dwbessa           #+#    #+#             */
/*   Updated: 2024/05/05 13:05:45 by dwbessa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_number(t_data *data)
{
	int	i;
	int	single_quotes = 0;
	int	double_quotes = 0;

	i = 0;
	while (data->raw_cmd[i])
	{
		if (data->raw_cmd[i] == 39)
			single_quotes++;
		else if (data->raw_cmd[i] == 34)
			double_quotes++;
		i++;
	}
	if (double_quotes == 0 && single_quotes == 0)
		return (1);
	else if (double_quotes % 2 != 0 || single_quotes % 2 != 0)
		return (0);
	return (1);
}

void	quote_error()
{
	printf("minishell: syntax error: even number of quotes\n");
}