/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:12:32 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/06/17 13:12:33 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_reverse(char *str, int i)
{
	int		k;
	char	*correct;

	k = 0;
	correct = malloc (i + 1);
	if (!correct)
		return (NULL);
	while (i > 0)
	{
		i--;
		correct[k] = str[i];
		k++;
	}
	correct [k] = '\0';
	ft_putstr(correct);
	return (correct);
}

static int	to_hex(unsigned int num)
{
	char	*hex;
	char	reverse[20];
	char	*correct;
	int		i;

	hex = "0123456789abcdef";
	if (num == 0)
	{
		ft_putstr("0");
		return (1);
	}
	i = 0;
	while (num > 0)
	{
		reverse[i] = hex[(num % 16)];
		num /= 16;
		i++;
	}
	correct = str_reverse(reverse, i);
	free (correct);
	correct = NULL;
	return (i);
}

int	print_x(va_list ap)
{
	int				og;
	unsigned int	l;
	int				count;

	count = 0;
	og = va_arg (ap, int);
	l = (unsigned int)(og);
	count = to_hex (l);
	return (count);
}
