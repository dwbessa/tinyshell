/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:26:12 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/06 17:30:00 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**expand_prompt(char **arg, t_list **env)
{
	t_list				*aux;
	char				*temp;
	int					i;
	int					len;
	extern unsigned int	g_exit_status;

	i = 0;
	while (arg[i])
	{
		aux = *env;
		if (!ft_strncmp(arg[i], "$?", 3))
		{
			free(arg[i]);
			arg[i] = ft_itoa(g_exit_status);
		}
		else if (!ft_strncmp(arg[i], "$", 1))
		{
			while (aux)
			{
				len = ft_strlen(arg[i] + 1);
				if (!ft_strncmp(arg[i] + 1, aux->content, len))
				{
					free(arg[i]);
					arg[i] = ft_strdup(ft_strchr(aux->content, '=') + 1);
					break ;
				}
				aux = aux->next;
			}
		}
		else if (!ft_strncmp(arg[i], "~", 1))
		{
			while (aux)
			{
				if (!ft_strncmp(aux->content, "HOME=", 5))
				{
					temp = ft_strjoin(aux->content + 5, arg[i] + 1);
					free(arg[i]);
					arg[i] = temp;
					break ;
				}
				aux = aux->next;
			}
		}
		i++;
	}
	return (arg);
}
