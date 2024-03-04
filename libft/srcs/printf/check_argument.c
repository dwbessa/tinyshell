/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessa <dbessa@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:13:46 by dbessa            #+#    #+#             */
/*   Updated: 2023/10/24 18:17:45 by dbessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_argument(const char *arg, int i, va_list ap)
{
	if (arg[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (arg[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (arg[i + 1] == 'd' || arg[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (arg[i + 1] == 'u')
		return (ft_putunsnbr(va_arg(ap, unsigned int)));
	else if (arg[i + 1] == 'p')
		return (ft_puthexa(va_arg(ap, unsigned long), 'p') + 2);
	else if (arg[i + 1] == 'x' || arg[i + 1] == 'X')
		return (ft_puthexa(va_arg(ap, unsigned int), arg[i + 1]));
	else if (arg[i + 1] == '%')
		return (ft_putchar('%'));
	return (0);
}
