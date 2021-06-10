#include "ft_printf.h"

int	argument_s(char *str, t_flags *flag)
{
	int		len;

	len = 0;
	if (str == NULL)
		str = "(null)";
	if (flag->minus == 0)
		len = argument_s_without_minus(flag, str) + len;
	else if (flag->minus > 0)
		len = argument_s_minus(flag, str) + len;
	return (len);
}

int	argument_s_without_minus(t_flags *flag, char *str)
{
	int		len;
	int		len_str;

	len = 0;
	len_str = ft_strlen(str);
	if (flag->precision >= 0 && flag->precision < len_str)
		len_str = flag->precision;
	if (flag->precision == 0)
		len_str = 0;
	if (flag->width - len_str > 0 && flag->zero == 0)
		len = write_symbol(' ', flag->width - len_str) + len;
	if (flag->width - len_str > 0 && flag->zero > 0)
		len = write_symbol('0', flag->width - len_str) + len;
	write(1, str, len_str);
	len = len_str + len;
	return (len);
}

int	argument_s_minus(t_flags *flag, char *str)
{
	int		len;
	int		len_str;

	len = 0;
	len_str = ft_strlen(str);
	if (flag->precision == 0)
		len_str = 0;
	if (flag->precision > 0 && flag->precision < len_str)
		len_str = flag->precision;
	write(1, str, len_str);
	if (flag->width - len_str > 0)
		len = write_symbol(' ', flag->width - len_str) + len;
	len = len_str + len;
	return (len);
}
