#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

void	chooser(char input, int *count, va_list *ap)
{
	write (1, "X", 1);
	return;
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
			chooser (*input, &count, &ap);
		}
		else
			write (1, input, 1);
		input ++;
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