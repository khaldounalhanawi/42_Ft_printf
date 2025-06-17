/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:12:14 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/06/17 13:12:17 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	devider_cal(long m)
{
	long	devider;

	devider = 1;
	while (devider <= m / 10)
	{
		devider *= 10;
	}
	return (devider);
}

int	print_d(va_list ap)
{
	char	out;
	int		devider;
	long	m;
	int		count;

	count = 0;
	m = (long)va_arg(ap, int);
	if (m < 0)
	{
		write (1, "-", 1);
		m = m * (-1);
		count ++;
	}
	devider = devider_cal (m);
	while (devider > 0)
	{
		out = (m / devider) + '0';
		write(1, &out, 1);
		m %= devider;
		devider /= 10;
		count ++;
	}
	return (count);
}
