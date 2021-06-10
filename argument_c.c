#include "ft_printf.h"

int	argument_c(char c, t_flags *flag)
{
	int	len;

	len = 0;
	if (flag->minus == 0)
		len = argument_c_without_minus(c, flag) + len;
	if (flag->minus > 0)
	{
		ft_putchar(c);
		if (flag->width > 1)
			len = write_sl(' ', flag->width) + len;
		len++;
	}
	return (len);
}

int	argument_c_without_minus(char c, t_flags *flag)
{
	int	len;

	len = 0;
	if (flag->zero == 0)
	{
		if (flag->width > 1)
			len = write_sl(' ', flag->width) + len;
	}
	else
	{
		if (flag->width > 1)
			len = write_sl('0', flag->width) + len;
	}
	ft_putchar(c);
	len++;
	return (len);
}
