#include "ft_printf.h"

int	working_argument(t_flags *flag, va_list ap)
{
	int		len;

	len = 0;
	if (flag->type == 'c')
		len = argument_c(va_arg(ap, int), flag) + len;
	if (flag->type == 's')
		len = argument_s(va_arg(ap, char *), flag) + len;
	if (flag->type == 'd' || flag->type == 'i')
		len = argument_d_i(va_arg(ap, int), flag) + len;
	if (flag->type == 'u')
		len = argument_u(va_arg(ap, unsigned int), flag) + len;
	if (flag->type == 'x')
		len = argument_x(va_arg(ap, unsigned int), flag) + len;
	if (flag->type == 'X')
		len = argument_x_big(va_arg(ap, unsigned int), flag) + len;
	if (flag->type == 'p')
		len = argument_p(va_arg(ap, unsigned long), flag) + len;
	if (flag->type == '%')
		len = argument_s("%", flag) + len;
	if (flag->type == '\0')
		return (len);
	return (len);
}
