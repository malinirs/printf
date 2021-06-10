#include "ft_printf.h"

int	write_sl(char symbol, int i)
{
	int		len;

	len = 0;
	while (i > 1)
	{
		ft_putchar(symbol);
		len++;
		i--;
	}
	return (len);
}

int	write_symbol(char symbol, int i)
{
	int		len;

	len = 0;
	while (i > 0)
	{
		ft_putchar(symbol);
		len++;
		i--;
	}
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
