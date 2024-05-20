/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:04:01 by aldantas          #+#    #+#             */
/*   Updated: 2024/05/20 16:40:00 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static int	count_chars(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(line[i])
	{
		if (line[i] != '\'' && line[i] != '\"')
			count++;
		i++;
	}
	return (count);
}

char	*remove_quotes2(char *line)
{
	char	*all_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	all_line = malloc((sizeof(char) * count_chars(line) + 1));
	if (!all_line)
		return (NULL);
	while (line[i])
	{
		if (line[i] != '\'' && line[i] != '\"')
			all_line[j++] = line[i];
		i++;
	}
	all_line[j] = '\0';
	return (all_line);
}

void	remove_quotes_all_prompt(t_word *prompt)
{
	char	*temp;

	temp = NULL;
	while(prompt)
	{
		temp = prompt->word;
		prompt->word = remove_quotes2(prompt->word);
		free(temp);
		prompt = prompt->next;
	}
}