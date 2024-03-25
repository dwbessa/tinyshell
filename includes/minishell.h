/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:08:00 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/24 19:53:58 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <term.h>
#include "../libft/includes/libft.h"

void		func_pwd(void);
void		func_cd(char **argument, t_list **envp);
void		func_echo(char **argument, char *prompt);
void		func_env(t_list **env);
void		func_exit(char **arg, char *prompt, t_list **envp, char *pwd);
void		func_export(char **arg, t_list **env);
void		print_env(void);
void		free_matrix(char **arguments);
void		free_all(char **arguments, char *prompt);
void		handle_builtin(char **arg, char *prompt, t_list **env, char *pwd);
void		mini_clear(void);
void		ms_sigint_handle(int signal);
void		ms_set_sighandle(void);
char		*shell_name(t_list *env);
t_list		*get_env_lst(void);
