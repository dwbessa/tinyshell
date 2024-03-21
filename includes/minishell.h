/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:08:00 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/21 16:18:09 by aldantas         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

char		*command_env(char **argument, int fd);
char		**store_env(void);
void		print_env(void);
void		free_matrix(char **arguments);
void		free_all(char **arguments, char *prompt);

/* bultins */
void	handle_builtin(char **argument, char *prompt, pid_t mini_pid);

/* pipe */
void	execute(char *argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	conflict(void);
void    exec_pipe(int argc, char **argv, char **envp);
int     have_pipe(char *prompt);


