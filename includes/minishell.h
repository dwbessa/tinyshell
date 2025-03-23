#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <signal.h>
# include <sys/stat.h>
# include <errno.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <term.h>
# include "../libft/includes/libft.h"

typedef struct s_word
{
	char			*word;
	int				fd_in;
	int				fd_out;
	int				status;
	pid_t			pid;
	unsigned int	flag;
	struct s_word	*head;
	struct s_list	*env;
	struct s_word	*next;
}	t_word;

typedef struct s_data
{
	t_list			*env;
	int				status;
	char			**envp;
	char			*pwd;
	char			*raw_cmd;
	struct s_word	*prompt;
}	t_data;

enum e_token
{
	MS_WORD,
	MS_PIPE,
	MS_REDIRECT_IN,
	MS_REDIRECT_OUT,
	MS_REDIRECT_FILE,
	MS_APPEND,
	MS_HEREDOC,
};

enum e_builtins
{
	MS_ECHO,
	MS_CD,
	MS_PWD,
	MS_EXPORT,
	MS_UNSET,
	MS_ENV,
	MS_EXIT,
};

/* parsers */
unsigned int	give_token(char *word, int last_flag);
void			remove_quotes_all_prompt(t_word *prompt);
char			*remove_quotes2(char *line);
int				parse_quotes(t_data *data);
int				syntax_errors(t_data *data);
int				check_pipe_syntax(t_data *data);
int				check_redir_syntax(t_data *data);
int				quote_number(t_data *data);
int				is_all_space(char *line);
int				executor(t_data *data);
int				ft_pipe(t_word *prompt);
int				do_redir(t_word *prompt);
int				redir_in(t_word *prompt);
int				redir_out(t_word *prompt);
int				append(t_word *prompt);
int				heredoc(t_word *prompt);
int				parse_prompt(t_data *data);
int				exec_command(t_data *data);
int				many_char(char *s, char c);
int				is_builtin(t_data *data);
int				func_pwd(t_word *prompt);
int				func_cd(t_word *prompt);
int				func_echo(t_word *prompt);
int				func_env(t_list *env, t_word *prompt);
int				func_export(t_word *prompt, t_list *env);
int				func_unset(t_word *prompt, t_list **env);
void			func_exit(t_data *data);
void			print_env(void);
void			handle_prompt(t_data *data);
void			free_matrix(char **arguments);
void			free_all(char **arguments, char *prompt);
void			mini_clear(void);
void			sigint_handle(int signal);
void			set_sighandle(void);
void			quote_error(void);
void			expand_prompt(t_word **prompt);
char			*shell_name(t_list *env);
char			**transform_list(t_word *prompt);
void			print_word(t_word **prompt);
void			free_prompt(t_word *prompt);
void			ms_lstadd_back(t_word **lst, t_word *new);
// int				get_word_len(char *line);
void			tokenize_prompt(t_word **prompt);
char			*use_path(char *arg, t_list *env);
char			**env_to_matrix(t_list *env);
void			redirect_stdio(t_word *prompt);
void			close_sentence_fd(t_word *prompt);
void			bin_exec_pipe(t_word *prompt);
void			close_fds(t_word *prompt);
void			exec_pipe(t_word *prompt);
void			wait_cmds(t_word *node);
void			close_pipe(int *fd);
t_list			*get_env_lst(void);
t_list			*ms_create_env_lst(void);
t_word			*ms_lstnew(void *word);
t_word			*get_last_word(t_word *prompt);
t_word			*tokenizer(t_data *data);
t_word			*create_word_lst(char *line, t_list *env_lst);
t_word			*next_command_pipe(t_word *prompt);

#endif
