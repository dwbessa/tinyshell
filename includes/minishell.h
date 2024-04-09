/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:08:00 by dbessa            #+#    #+#             */
/*   Updated: 2024/04/06 16:56:32 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int			exec_command(char **arg, t_list **env);
int			many_char(char *s, char c);
int			is_builtin(char **arg, char *prompt, t_list **env, char *pwd);
int			func_pwd(void);
int			func_cd(char **argument, t_list **envp);
int			func_echo(char **argument);
int			func_env(t_list **env);
int			func_export(char **arg, t_list *env);
int			func_unset(char **arg, t_list **env);

void		func_exit(char **arg, char *prompt, t_list **envp, char *pwd);
void		print_env(void);
void		handle_prompt(char *prompt, char **arg, char *pwd, t_list **env);
void		free_matrix(char **arguments);
void		free_all(char **arguments, char *prompt);
void		mini_clear(void);
void		sigint_handle(int signal);
void		set_sighandle(void);

char		*shell_name(t_list *env);
char		**expand_prompt(char **arg, t_list **env);

t_list		*get_env_lst(void);

#endif
