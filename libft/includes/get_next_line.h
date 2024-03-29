/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:41:26 by dbessa            #+#    #+#             */
/*   Updated: 2024/03/29 11:03:23 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

char			*get_next_line(int fd);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin_free2(char *s1, char *s2);

#endif
