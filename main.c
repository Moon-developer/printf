
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

// converts the number to the correct base type
char	*ft_convert(unsigned int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	static char buffer[50]; 
	char *ptr; 

	ptr = &buffer[49]; 
	*ptr = '\0';

	while(num != 0) 
	{
		*--ptr = Representation[ num % base];
		num /= base;
	}
	return(ptr); 
}

// print strings
void	ft_printstr(va_list arg)
{
	char		*str;

	str = va_arg(arg, char *);
	ft_putstr(str);
}

// print intergers
void	ft_printint(va_list arg)
{
	int	 	i;

	i = va_arg(arg, int);
	if (i < 0)
	{
		i = -i;
		ft_putchar('-');
	}
	ft_putstr(ft_convert(i, 10));

}

// print char
void	ft_printchar(va_list arg)
{
	int	 	i;

	i = va_arg(arg, int);
	ft_putchar(i);
}

// print octal
void	ft_printoct(va_list arg)
{
	int	 	i;

	i = va_arg(arg, unsigned int);
	ft_putstr(ft_convert(i, 8));
}

// print hexidecimal
void	ft_printhex(va_list arg)
{
	int	 	i;

	i = va_arg(arg, unsigned int);
	ft_putstr(ft_convert(i, 16));
}

void 	ft_flag(char letter, va_list arg)
{
	if (letter == 'c')
		ft_printchar(arg);
	else if (letter == 'd')
		ft_printint(arg);
	else if (letter == 's')
		ft_printstr(arg);
	else if (letter == 'o')
		ft_printoct(arg);
	else if (letter == 'x')
		ft_printhex(arg);
}

int	random_flags(char *str, int pos)
{
	int	tempos;

	tempos = pos;
	if (str[pos] == '\\')
		if (str[pos + 1] == 'n')
		{
			ft_putstr("\n");
			return (tempos + 2);
		}
	return (tempos);
}

// printf 
int    ft_printf(const char *format, ...)
{
	char	*string;
	int	pos;
	int	length;
	va_list	arg;

	pos = 0;
	length = ft_strlen(format);
	va_start(arg, format);
	string = format;
	while (pos < length)
	{
		while (string[pos] != '%' && pos < length)
		{
			pos = random_flags(string, pos);
			ft_putchar(string[pos]);
			pos++;
		}
		pos++;
		ft_flag(string[pos], arg);
		pos++;
	}
	va_end(arg);
	return(0);
}

int main( void )
{
	ft_printf("%s \t %s \n\n", "hello", "world");
	return (1);
}
