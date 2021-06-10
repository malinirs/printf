#include "ft_printf.h"

char	*parsing_str_point(char *str, t_flags *flag)
{
	if (ft_isdigit(*str) == 1)
	{
		flag->precision = check_digit(str);
		while (ft_isdigit(*str) == 1)
			str++;
	}
	else
	{
		flag->precision = 0;
		if (ft_isdigit(*(str++)) == 1)
		{
			flag->width = check_digit(str);
			while (ft_isdigit(*str) == 1)
				str++;
		}
	}
	str++;
	return (str);
}

char	*parsing_str_zero_or_minus(char *str, t_flags *flag)
{
	if (*str == '-')
	{
		flag->minus = 1;
		flag->zero = 0;
	}
	else if (flag->minus == 0)
		flag->zero = 1;
	str++;
	return (str);
}

char	*parsing_str_star(char *str, t_flags *flag, va_list ap)
{
	int		digit;

	digit = va_arg(ap, int);
	if (*(--str) == '.')
	{
		if (digit > 0)
			flag->precision = digit;
		if (digit < 0)
			flag->precision = -1;
		str++;
	}
	else
	{
		if (digit < 0)
		{
			flag->minus = 1;
			flag->zero = 0;
			digit = digit * (-1);
		}
		flag->width = digit;
		str++;
	}
	str++;
	return (str);
}

char	*parsing_str(char *str, va_list ap, t_flags *flag)
{
	while (*str == '0' || *str == '-' || ft_isdigit(*str) == 1 || \
			  *str == '.' || *str == '*')
	{
		if (ft_isdigit(*str) == 1 && str[0] > '0')
		{
			flag->width = check_digit(str);
			while (ft_isdigit(*str) == 1)
				str++;
		}
		if (*str == '.')
		{
			str++;
			parsing_str_point(str, flag);
			while (ft_isdigit(*str) == 1)
				str++;
		}
		if (*str == '0' || *str == '-')
			str = parsing_str_zero_or_minus(str, flag);
		if (*str == '*')
			str = parsing_str_star(str, flag, ap);
	}
	flag->type = *str;
	return (str);
}
