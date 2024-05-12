/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:18 by dbessa            #+#    #+#             */
/*   Updated: 2024/05/12 03:50:51 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

static char	*transform_arg(char *arg, t_list *env)
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

static void	pid_zero(t_word *prompt, char **new_env)
{
	char	**arg;

	arg = transform_list(prompt);
	if (execve(arg[0], arg, new_env) == -1)
	{
		if (errno == ENOENT)
			printf("minishell: command not found: %s\n", arg[0]);
		else
			printf("%s: %s\n", arg[0], strerror(errno));
		free_matrix(arg);
		exit(127);
	}
	else
	{
		free_matrix(arg);
		exit(EXIT_SUCCESS);
	}
}

int	exec_command(t_data *data)
{
	int					status;
	extern unsigned int	g_exit_status;
	t_word				*prompt;

	prompt = data->prompt->head;
	if (ft_strncmp("./", prompt->word, 2))
		prompt->word = use_path(prompt->word, data->env);
	prompt->pid = fork();
	data->envp = env_to_matrix(data->env);
	if (prompt->pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (prompt->pid == 0)
		pid_zero(prompt, data->envp);
	else
		waitpid(prompt->pid, &status, 0);
	free_matrix(data->envp);
	g_exit_status = WEXITSTATUS(status);
	return (1);
}
