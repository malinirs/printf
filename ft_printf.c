#include "ft_printf.h"

t_flags	assignment_flags(void)
{
	t_flags	flag;

	flag.width = 0;
	flag.precision = -1;
	flag.type = ' ';
	flag.minus = 0;
	flag.zero = 0;
	return (flag);
}

int	check_digit(char *str)
{
	int		i;
	int		digit;

	i = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	digit = ft_atoi(str);
	return (digit);
}

int 	check_flags(char *str, va_list ap)
{
	int		len;
	t_flags	flag;

	len = 0;
	while (*str)
	{
		if (*str != '%' && *str)
			len = write_symbol(*str, 1) + len;
		if (*str == '%')
		{
			flag = assignment_flags(); /** каждый раз обнуляются атрибуты,
 * возвращается указатель на структуру, который каждый раз теряется. Не нужно
 * присваивать в flag, нужно сделать тип не void */
			str = parsing_str(++str, ap, &flag);
			len = working_argument(&flag, ap) + len;
		}
		if (*str)
			str++;
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	char	*string;
	int		len;
	va_list	ap;

	string = (char *)str;
	va_start(ap, str);
	len = check_flags(string, ap);
	va_end(ap);
	return (len);
}
