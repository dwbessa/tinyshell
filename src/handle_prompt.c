#include "minishell.h"

void	handle_prompt(t_data *data)
{
	if (!parse_quotes(data))
		return ;
	if (!parse_prompt(data))
		return ;
	remove_quotes_all_prompt(data->prompt);
	executor(data);
	wait_cmds(data->prompt);
	free_prompt(data->prompt);
}

int	parse_prompt(t_data *data)
{
	if (!is_all_space(data->raw_cmd))
		add_history(data->raw_cmd);
	data->prompt = create_word_lst(data->raw_cmd, data->env);
	if (!data->prompt)
		return (0);
	tokenize_prompt(&data->prompt);
	expand_prompt(&data->prompt);
	if (syntax_errors(data))
	{
		free_prompt(data->prompt);
		return (0);
	}
	return (1);
}

void	tokenize_prompt(t_word	**prompt)
{
	t_word	*token;
	int		last_flag;

	token = (*prompt)->head;
	last_flag = token->flag;
	while (token)
	{
		token->flag = give_token(token->word, last_flag);
		last_flag = token->flag;
		token = token->next;
	}
}

unsigned int	give_token(char *word, int last_flag)
{
	if (!word)
		return (-1);
	if (!ft_strncmp("|", word, 2))
		return (MS_PIPE);
	else if (!ft_strncmp("<", word, 2))
		return (MS_REDIRECT_IN);
	else if (!ft_strncmp(">", word, 2))
		return (MS_REDIRECT_OUT);
	else if (!ft_strncmp(">>", word, 3))
		return (MS_APPEND);
	else if (!ft_strncmp("<<", word, 3))
		return (MS_HEREDOC);
	else if (last_flag == MS_REDIRECT_OUT || last_flag == MS_REDIRECT_IN
		|| last_flag == MS_HEREDOC || last_flag == MS_APPEND)
		return (MS_REDIRECT_FILE);
	return (MS_WORD);
}

void	print_word(t_word **prompt)
{
	t_word	*print;

	print = *prompt;
	while (print != NULL)
	{
		printf("WORD = %s\nTOKEN = %d\n", print->word, print->flag);
		print = print->next;
	}
}
