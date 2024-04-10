/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:18 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/10 15:17:09 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_matrix(t_list *env)
{
	char	**new_env;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(env);
	new_env = malloc(sizeof(char *) * (len + 1));
	if (!new_env)
		return (NULL);
	while (env)
	{
		new_env[i] = ft_strdup(env->content);
		env = env->next;
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

char	*transform_arg(char *arg, t_list *env)
{
	char	**all_path;
	char	*path;
	char	*temp;
	int		i;

	i = 0;
	all_path = ft_split(env->content + 5, ':');
	while (all_path[i])
	{
		temp = ft_strjoin(all_path[i], "/");
		path = ft_strjoin(temp, arg);
		free(temp);
		if (access(path, F_OK) == 0)
		{
			free(arg);
			arg = ft_strdup(path);
			free(path);
			free_matrix(all_path);
			return (arg);
		}
		free(path);
		i++;
	}
	free_matrix(all_path);
	return (arg);
}

char	*use_path(char *arg, t_list *env)
{
	while (env)
	{
		if (!ft_strncmp(env->content, "PATH=", 5))
		{
			arg = transform_arg(arg, env);
			break ;
		}
		env = env->next;
	}
	return (arg);
}

void	pid_zero(char **arg, char **new_env)
{
	if (execve(arg[0], arg, new_env) == -1)
	{
		if (errno == ENOENT)
			printf("minishell: command not found: %s\n", arg[0]);
		else
			printf("%s: %s\n", arg[0], strerror(errno));
		exit(127);
	}
	else
		exit(EXIT_SUCCESS);
}

int	exec_command(t_data *data)
{
	int					status;
	extern unsigned int	g_exit_status;

	if (ft_strncmp("./", data->arg[0], 2))
		data->arg[0] = use_path(data->arg[0], data->env);
	data->pid = fork();
	data->envp = env_to_matrix(data->env);
	if (data->pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (data->pid == 0)
		pid_zero(data->arg, data->envp);
	else
		waitpid(data->pid, &status, 0);
	free_matrix(data->envp);
	g_exit_status = WEXITSTATUS(status);
	return (1);
}
