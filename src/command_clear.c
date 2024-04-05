/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:18 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/05 13:44:40 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char	*env_to_matrix(t_list **env)
{

}*/

char	**use_path(char **arg, t_list **envp)
{
	char	**all_path;
	char	*path;
	char	*part_path;
	t_list	*env;

	env = *envp;
	while (env)
	{
		if(!ft_strncmp(env->content, "PATH=", 5))
		{
			all_path = ft_split(env->content + 5, ':');
			while (all_path)
			{
				path = ft_strjoin(*all_path, "/");
				part_path = ft_strjoin(path, arg[0]);
				if (access(path, F_OK))
				{
					arg[0] = ft_strdup(part_path);
					return (arg);
				}
				all_path++;
			}
			break ;
		}
		env = env->next;
	}
	return (arg);
}

int	command_clear(char **arg, t_list **env)
{
	pid_t	pid;
	int		status;
	char	**arg2;

	arg2 = use_path(arg, env);
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		char *argv[] = {"/usr/bin/clear", NULL};
		execve(argv[0], argv, __environ);
		perror("clear failed");
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	int i = 0;
	while (arg2[i])
	{
		printf("%s\n", arg2[i]);
		i++;
	}
	return (1);
}
