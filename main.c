#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(char *in, ...)
{
	int		count;
	char	*str;
	va_list ap;
	char	*txt;

	str = in;
	count = 0;
	va_start (ap, in);
	while (*in)
	{
		if (*in == '%')
		{
			in ++;
			if (*in == 'd')
			{
				int d = va_arg (ap, int);
				printf ("%d", d);
			}
			else if (*in == 's')
			{
				txt = va_arg (ap, char *);
				while (*txt)
				{
					write (1, txt, 1);
					txt ++;
				}
			}
		}
		else
			write (1, in, 1);
		in ++;
		count ++;
	}
	va_end (ap);
	return (count);
}

int	main()
{
	int		num;
	char	tomato[6] = "shoko";
	char	potato[5] = "carb";
	
	num = 77;
	
	ft_printf ("so there is %d and %s and %s\n", num, tomato, potato);
	return (0);
}