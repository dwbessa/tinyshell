#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_putunsnbr(unsigned int nb);
int		ft_puthexa(unsigned long d, int arg);
int		check_argument(const char *arg, int i, va_list ap);

#endif
