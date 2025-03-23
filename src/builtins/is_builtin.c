#include "minishell.h"

int	is_builtin(t_data *data)
{
	int		builtin;
	t_word	*prompt;

	prompt = data->prompt->head;
	builtin = 0;
	if (!ft_strncmp(prompt->word, "pwd", 4))
		builtin = func_pwd(prompt);
	else if (!ft_strncmp(prompt->word, "cd", 3))
		builtin = func_cd(data->prompt);
	else if (!ft_strncmp(prompt->word, "echo", 5))
		builtin = func_echo(data->prompt);
	else if (!ft_strncmp(prompt->word, "env", 4))
		builtin = func_env(prompt->env, prompt);
	else if (!ft_strncmp(prompt->word, "exit", 5))
		func_exit(data);
	else if (!ft_strncmp(prompt->word, "export", 7))
		builtin = func_export(prompt, prompt->env);
	else if (!ft_strncmp(prompt->word, "unset", 6))
		builtin = func_unset(prompt, &prompt->env);
	return (builtin);
}
