#include "ft_printf.h"

int	argument_d_i(int digit, t_flags *flag)
{
	int		len;

	len = 0;
	if (digit == 0 && flag->precision == 0)
	{
		len = write_symbol(' ', flag->width) + len;
		return (len);
	}
	if (digit >= 0)
		len = argument_d_i_positive(flag, digit) + len;
	if (digit < 0)
		len = argument_d_i_negative(flag, digit) + len;
	return (len);
}

int	argument_d_i_positive(t_flags *flag, long int digit)
{
	int		len;
	char	*str;
	int		len_str;
	int		len_pres;

	len = 0;
	len_pres = 0;
	str = ft_itoa_mod(digit);
	len_str = ft_strlen(str);
	if (flag->precision > len_str)
		len_pres = flag->precision - len_str;
	if (flag->minus == 0)
		len = argument_d_i_pos(flag, len_str, len_pres, str) + len;
	if (flag->minus > 0)
		len = argument_d_i_pos_min(flag, len_str, len_pres, str) + len;
	free(str);
	return (len);
}

int	argument_d_i_negative(t_flags *flag, long int digit)
{
	int		len;
	char	*str;
	int		len_str;
	int		len_pres;

	len = 0;
	len_pres = 0;
	digit = -digit;
	str = ft_itoa_mod(digit);
	len_str = ft_strlen(str);
	if (flag->precision > len_str)
		len_pres = flag->precision - len_str;
	if (flag->minus == 0)
		len = argument_d_i_neg(flag, len_str, len_pres, str) + len;
	if (flag->minus > 0)
		len = argument_d_i_neg_min(flag, len_str, len_pres, str) + len;
	free(str);
	return (len);
}
