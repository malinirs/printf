#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h> /** для макросов */
# include <stdio.h>
# include <stdlib.h>

typedef struct s_flags
{
	int		width;
	int		precision;
	char	type;
	int		minus;
	int		zero;
}				t_flags;

t_flags	assignment_flags(void);
int		check_flags(char *str, va_list ap);
int		ft_printf(const char *str, ...);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
int		check_digit(char *str);
char	*parsing_str_point(char *str, t_flags *flag);
char	*parsing_str_zero_or_minus(char *str, t_flags *flag);
char	*parsing_str(char *str, va_list ap, t_flags *flag);
int		ft_isdigit(int c);
char	*parsing_str_star(char *str, t_flags *flag, va_list ap);
int		working_argument(t_flags *flag, va_list ap);
int		argument_c(char c, t_flags *flag);
int		write_symbol(char symbol, int i);
int		argument_s(char *str, t_flags *flag);
int		ft_strlen(char *str);
int		write_sl(char symbol, int i);
int		argument_s_without_minus(t_flags *flag, char *str);
int		argument_s_minus(t_flags *flag, char *str);
int		argument_c_without_minus(char c, t_flags *flag);
int		argument_d_i(int digit, t_flags *flag);
char	*ft_itoa_mod(long long int n);
int		argument_d_i_pos(t_flags *flag, int len_str, int len_pres, char *str);
int		argument_d_i_pos_min(t_flags *flag, int len_str, int len_pres, \
			  char *str);
int		argument_d_i_neg(t_flags *flag, int len_str, int len_pres, char *str);
int		argument_d_i_neg_min(t_flags *flag, int len_str, int len_pres, \
			  char *str);
int		argument_d_i_positive(t_flags *flag, long int digit);
int		argument_d_i_negative(t_flags *flag, long int digit);
int		argument_u(unsigned int digit, t_flags *flag);
int		argument_x(unsigned int digit, t_flags *flag);
char	*ft_itoa_mod(long long int n);
char	*ft_itoa_mod_six(long long int n);
int		argument_x_big(unsigned int digit, t_flags *flag);
char	*ft_itoa_mod_six_big(long long int n);
int		argument_p(unsigned long digit, t_flags *flag);
int		argument_p_pos(t_flags *flag, int len_str, int len_pres, char *str);
int		argument_p_pos_min(t_flags *flag, int len_str, int len_pres, char *str);
int		digit_NULL(t_flags *flag);

#endif