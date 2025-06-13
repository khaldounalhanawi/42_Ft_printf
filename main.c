#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		len_total;
	char	*p;
	char	*original;

	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	len_total = len1 + len2 + 1;
	p = malloc (len_total * sizeof(char));
	if (!p)
		return (NULL);
	original = p;
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (original);
}

char	*ft_itoh(unsigned int num)
{
	char	*base;

	base = "0123456789abcdef";
	
	return ("abc");
}

int	print_s(va_list ap)
{
	int	count;
	char	*str;
	
	count = 0;
	str = va_arg(ap, char *);
	while (*str)
	{
		write (1, str, 1);
		str ++;
		count++;
	}
	return (count);
}

int	print_c(va_list ap)
{
	char	c;

	c = (unsigned char)va_arg (ap, int);
	write (1, &c, 1);
	return (1);
}

int	print_p(va_list ap)
{
	unsigned int	p;
	char			*str;
	char			*final;
	int				count;

	count = 0;
	p = va_arg (ap, unsigned int);
	str = ft_itoh(p); ////////
	final = ft_strjoin ("0x", str);
	while (final[count])
	{
		write (1, &final[count], 1);
		count++;
	}
	free (final);
	final = NULL;
	return (count);
}

int	chooser(char input, va_list ap)
{
	if (input == 'c')
		return (print_c(ap));
	if (input == 's')
		return (print_s(ap));
	if (input == 'p')
		return (print_p(ap));
	// if (input == 'd')
	// 	return (print_d(ap));
	// if (input == 'i')
	// 	return (print_i(ap));
	// if (input == 'u')
	// 	return (print_u(ap));
	// if (input == 'x')
	// 	return (print_x(ap));
	// if (input == 'X')
	// 	return (print_X(ap));
	// if (input == '%')
	// 	return (print_percent(ap));
	//return (-1);
}

int	ft_printf(char *input, ...)
{
	int		count;
	va_list ap;

	count = 0;
	va_start (ap, input);
	while (*input)
	{
		if (*input == '%')
		{
			input ++;
			if (!ft_strchr("cspdiuxX%%", *input))
				break;
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

int	main()
{
	int		num;
	char	tomato[6] = "shoko";
	char	potato[5] = "carb";
	int		my;
	int		original;
	char	cc;
	
	num = 77;
	cc = 'F';
	
	
	my = 0;
	original = 0;

	// my = ft_printf ("so there is %c and %s and %s\n", cc, tomato, potato);
	// printf ("my:       %d\n", my);
	
	original = printf ("so %p there is %c and %s and %s\n", &num, cc, tomato, potato);
	printf ("original: %d\n", original);


	return (0);
}