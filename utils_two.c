#include "ft_printf.h"

char	*ft_itoa_mod(long long int n)
{
	char			*str;
	int				len;
	long long int	temp;

	temp = n;
	len = 0;
	if (temp == 0)
		len = 1;
	while (temp > 0)
	{
		temp = temp / 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

static char	check(int temp)
{
	char	c;

	if (temp > 9)
	{
		if (temp == 10)
			c = 'a';
		if (temp == 11)
			c = 'b';
		if (temp == 12)
			c = 'c';
		if (temp == 13)
			c = 'd';
		if (temp == 14)
			c = 'e';
		if (temp == 15)
			c = 'f';
	}
	else
		c = temp + '0';
	return (c);
}

char	*ft_itoa_mod_six(long long int n)
{
	char			*str;
	int				len;
	long long int	temp;

	temp = n;
	len = 0;
	if (temp == 0)
		len = 1;
	while (temp > 0)
	{
		temp = temp / 16;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		temp = n % 16;
		str[len - 1] = check(temp);
		n = n / 16;
		len--;
	}
	return (str);
}

static char	check_big(int temp)
{
	char	c;

	if (temp > 9)
	{
		if (temp == 10)
			c = 'A';
		if (temp == 11)
			c = 'B';
		if (temp == 12)
			c = 'C';
		if (temp == 13)
			c = 'D';
		if (temp == 14)
			c = 'E';
		if (temp == 15)
			c = 'F';
	}
	else
		c = temp + '0';
	return (c);
}

char	*ft_itoa_mod_six_big(long long int n)
{
	char			*str;
	int				len;
	long long int	temp;

	temp = n;
	len = 0;
	if (temp == 0)
		len = 1;
	while (temp > 0)
	{
		temp = temp / 16;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		temp = n % 16;
		str[len - 1] = check_big(temp);
		n = n / 16;
		len--;
	}
	return (str);
}
