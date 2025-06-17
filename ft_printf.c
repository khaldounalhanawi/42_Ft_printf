/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:11:55 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/06/17 13:11:57 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	chooser(char input, va_list ap)
{
	if (input == 'c')
		return (print_c(ap));
	if (input == 's')
		return (print_s(ap));
	if (input == 'p')
		return (print_p(ap));
	if (input == 'd')
		return (print_d(ap));
	if (input == 'i')
		return (print_d(ap));
	if (input == 'u')
		return (print_u(ap));
	if (input == 'x')
		return (print_x(ap));
	if (input == 'X')
		return (print_xc(ap));
	if (input == '%')
		return (print_percent());
	return (-1);
}

int	ft_printf(const char *input, ...)
{
	int		count;
	va_list	ap;

	count = 0;
	va_start (ap, input);
	while (*input)
	{
		if (*input == '%')
		{
			input ++;
			if (!ft_strchr("cspdiuxX%%", *input))
				break ;
			count += chooser (*input, ap);
		}
		else
		{
			write (1, input, 1);
			count ++;
		}
		input ++;
	}
	va_end (ap);
	return (count);
}
