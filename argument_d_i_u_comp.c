#include "ft_printf.h"

int	argument_d_i_pos(t_flags *flag, int len_str, int len_pres, char *str)
{
	int		len;

	len = 0;
	if (flag->precision == -1 && flag->zero == 0)
		len = write_symbol(' ', flag->width - len_str) + len;
	if (flag->precision == -1 && flag->zero > 0)
		len = write_symbol('0', flag->width - len_str) + len;
	if (flag->precision == 0)
	{
		if (flag->width > 0)
			len = write_symbol(' ', flag->width - len_str) + len;
		if (flag->width == 0)
			len = write_symbol(' ', flag->width - len_str) + len;
	}
	if (flag->precision > 0)
	{
		len = write_symbol(' ', flag->width - len_str - len_pres) + len;
		len = write_symbol('0', len_pres) + len;
	}
	write(1, str, len_str);
	return (len + len_str);
}

int	argument_d_i_pos_min(t_flags *flag, int len_str, int len_pres, char *str)
{
	int		len;

	len = 0;
	if (flag->precision == -1 && flag->zero == 0)
	{
		write(1, str, len_str);
		len = write_symbol(' ', flag->width - len_str) + len;
	}
	if (flag->precision == 0)
	{
		write(1, str, len_str);
		len = write_symbol(' ', flag->width - len_str) + len;
	}
	if (flag->precision > 0)
	{
		len = write_symbol('0', len_pres) + len;
		write(1, str, len_str);
		len = write_symbol(' ', flag->width - len_str - len_pres) + len;
	}
	return (len + len_str);
}

int	argument_d_i_neg(t_flags *flag, int len_str, int len_pres, char *str)
{
	int		len;

	len = 0;
	if (flag->precision == -1)
	{
		if (flag->zero == 0)
			len = write_symbol(' ', flag->width - len_str - 1) + len;
		len = write_symbol('-', 1) + len;
		if (flag->zero > 0)
			len = write_symbol('0', flag->width - len_str - 1) + len;
	}
	if (flag->precision == 0)
	{
		len = write_symbol(' ', flag->width - len_str - 1) + len;
		len = write_symbol('-', 1) + len;
	}
	if (flag->precision > 0)
	{
		len = write_symbol(' ', flag->width - len_str - len_pres - 1) + \
			  len;
		len = write_symbol('-', 1) + len;
		len = write_symbol('0', len_pres) + len;
	}
	write(1, str, len_str);
	return (len + len_str);
}

int	argument_d_i_neg_min(t_flags *flag, int len_str, int len_pres, char *str)
{
	int		len;

	len = 0;
	if (flag->precision == -1 && flag->zero == 0)
	{
		len = write_symbol('-', 1) + len;
		write(1, str, len_str);
		len = write_symbol(' ', flag->width - len_str - 1) + len;
	}
	if (flag->precision == 0)
	{
		len = write_symbol('-', 1) + len;
		write(1, str, len_str);
		if (flag->width > 0)
			len = write_symbol(' ', flag->width - len_str - 1) + len;
	}
	if (flag->precision > 0)
	{
		len = write_symbol('-', 1) + len;
		len = write_symbol('0', len_pres) + len;
		write(1, str, len_str);
		len = write_symbol(' ', flag->width - len_str - len_pres - 1) + \
			  len;
	}
	return (len + len_str);
}
