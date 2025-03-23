#include "minishell.h"

void	*add_declare(void *content)
{
	char	*str_content;

	str_content = (char *)content;
	str_content = ft_strjoin("declare -x ", str_content);
	return (str_content);
}

void	sort_env(t_list *env, t_word *prompt)
{
	t_list	*export_env;
	t_list	*export_lst;

	export_env = ft_lstcopy(env);
	if (!export_env)
		return ;
	ft_sortlist(export_env, ft_strcmp);
	export_lst = ft_lstmap(export_env, add_declare, free);
	ft_lstclear(&export_env, free);
	func_env(export_lst, prompt);
	ft_lstclear(&export_lst, free);
}

int	update_var(char *arg, t_list *env)
{
	t_list	*aux;
	int		j;

	aux = env;
	while (env)
	{
		j = many_char(env->content, '=');
		if (!ft_strncmp(env->content, arg, j))
		{
			free(env->content);
			env->content = ft_strdup(arg);
			return (1);
		}
		env = env->next;
	}
	env = aux;
	return (0);
}

int	export_cmd(t_word *export, t_list *env)
{
	t_list				*node;
	extern unsigned int	g_exit_status;

	g_exit_status = 0;
	while (export)
	{
		if (ft_isdigit(*export->word))
		{
			printf("minishell: export: `%s`: "
				"not a valid identifier\n", export->word);
			g_exit_status = 1;
		}
		else if (!update_var(export->word, env))
		{
			node = ft_lstnew(ft_strdup(export->word));
			if (!node)
			{
				ft_lstclear(&node, free);
				return (g_exit_status);
			}
			ft_lstadd_back(&env, node);
		}
		export = export->next;
	}
	return (g_exit_status);
}

int	func_export(t_word *prompt, t_list *env)
{
	extern unsigned int	g_exit_status;
	t_word				*export;

	export = prompt->head;
	if (!export->next)
	{
		sort_env(env, prompt);
		return (1);
	}
	export = export->next;
	g_exit_status = export_cmd(export, env);
	return (1);
}
