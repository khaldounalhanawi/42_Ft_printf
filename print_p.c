/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:12:20 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/06/17 13:12:23 by kalhanaw         ###   ########.fr       */
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
	ft_putstr ("0x");
	ft_putstr(correct);
	return (correct);
}

static int	to_hex(unsigned long num)
{
	char	*hex;
	char	reverse[20];
	char	*correct;
	int		i;

	hex = "0123456789abcdef";
	if (num == 0)
	{
		ft_putstr("0x0");
		return (3);
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
	return (i + 2);
}

int	print_p(va_list ap)
{
	void			*p;
	unsigned long	l;
	int				count;

	count = 0;
	p = va_arg (ap, void *);
	if (!p)
	{
		ft_putstr ("(nil)");
		return (5);
	}
	l = (unsigned long) p;
	count = to_hex (l);
	return (count);
}
