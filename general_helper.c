/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:12:02 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/06/17 13:12:04 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	if (ch == '\0')
	{
		while (*s != ch)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
	{
		write (1, s, 1);
		s++;
	}
}
