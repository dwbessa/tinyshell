/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:18 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/06 17:23:13 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_matrix(t_list **env)
{
	char	**new_env;
	t_list	*aux;
	int		len;
	int		i;

	i = 0;
	aux = *env;
	len = ft_lstsize(aux);
	new_env = malloc(sizeof(char *) * (len + 1));
	if (!new_env)
		return (NULL);
	while (aux)
	{
		new_env[i] = ft_strdup(aux->content);
		aux = aux->next;
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

char	*use_path(char *arg, t_list **envp)
{
	t_list	*env;

	env = *envp;
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

int	exec_command(char **arg, t_list **env)
{
	pid_t				pid;
	int					status;
	extern unsigned int	g_exit_status;
	char				**new_env;

	if (ft_strncmp("./", arg[0], 2))
		arg[0] = use_path(arg[0], env);
	pid = fork();
	new_env = env_to_matrix(env);
	if (pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		pid_zero(arg, new_env);
	else
		waitpid(pid, &status, 0);
	free_matrix(new_env);
	g_exit_status = WEXITSTATUS(status);
	return (1);
}
