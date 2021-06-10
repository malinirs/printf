#include "ft_printf.h"

int	argument_p(unsigned long digit, t_flags *flag)
{
	int		len;
	char	*str;
	int		len_str;
	int		len_pres;

	len = 0;
	len_pres = 0;
	if (digit > 9)
		str = ft_itoa_mod_six(digit);
	else
		str = ft_itoa_mod(digit);
	len_str = ft_strlen(str);
	if (digit == 0)
	{
		len = digit_NULL(flag) + len;
		return (len);
	}
	if (flag->precision > len_str)
		len_pres = flag->precision - len_str;
	if (flag->minus == 0)
		len = argument_p_pos(flag, len_str, len_pres, str) + len;
	if (flag->minus > 0)
		len = argument_p_pos_min(flag, len_str, len_pres, str) + len;
	free(str);
	return (len + 2);
}

int	digit_NULL(t_flags *flag)
{
	int		len;

	len = 2;
	if (flag->precision == -1)
	{
		if (flag->width > 0 && flag->minus == 0)
			len = write_symbol(' ', flag->width - 3) + len;
		write(1, "0x0", 3);
		if (flag->width > 0 && flag->minus > 0)
			len = write_symbol(' ', flag->width - 3) + len;
		len++;
	}
	if (flag->precision == 0)
	{
		if (flag->width > 0 && flag->minus == 0)
			len = write_symbol(' ', flag->width - 2) + len;
		write(1, "0x", 2);
	}
	if (flag->precision > 0)
	{
		write(1, "0x", 2);
		len = write_symbol('0', flag->precision) + len;
	}
	return (len);
}

int	argument_p_pos(t_flags *flag, int len_str, int len_pres, char *str)
{
	int		len;

	len = 0;
	if (flag->precision == -1)
	{
		if (flag->zero == 0)
			len = write_symbol(' ', flag->width - len_str - 2) + len;
		write(1, "0x", 2);
		if (flag->zero > 0)
			len = write_symbol('0', flag->width - len_str - 2) + len;
	}
	if (flag->precision == 0)
	{
		len = write_symbol(' ', flag->width - len_str - 2) + len;
		write(1, "0x", 2);
	}
	if (flag->precision > 0)
	{
		len = write_symbol(' ', flag->width - len_str - len_pres - 2) + len;
		write(1, "0x", 2);
		len = write_symbol('0', len_pres) + len;
	}
	write(1, str, len_str);
	return (len + len_str);
}

int	argument_p_pos_min(t_flags *flag, int len_str, int len_pres, char *str)
{
	int		len;

	len = 0;
	if (flag->precision == -1 && flag->zero == 0)
	{
		write(1, "0x", 2);
		write(1, str, len_str);
		len = write_symbol(' ', flag->width - len_str - 2) + len;
	}
	if (flag->precision == 0)
	{
		write(1, "0x", 2);
		write(1, str, len_str);
		len = write_symbol(' ', flag->width - len_str - 2) + len;
	}
	if (flag->precision > 0)
	{
		write(1, "0x", 2);
		len = write_symbol('0', len_pres) + len;
		write(1, str, len_str);
		len = write_symbol(' ', flag->width - len_str - len_pres) + len;
	}
	return (len + len_str);
}
