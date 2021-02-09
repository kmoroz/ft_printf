/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 14:07:39 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/09 10:47:30 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct		s_recipe
{
	int			minus_flag;
	int			zero_flag;
	int			space_flag;
	int			plus_flag;
	int			hash_flag;
	int			width;
	int			precision;
	int			null_precision;
	char		type;
	char		length;
}					t_recipe;

int					ft_printf(const char *print_me, ...);
int					parse(va_list *arguments, const char **print_me,
t_recipe *recipe);
int					parse_flag(t_recipe *recipe, const char **print_me);
int					parse_precision(va_list *arguments, t_recipe *recipe,
const char **print_me);
int					parse_width(va_list *arguments, t_recipe *recipe,
const char **print_me);
char				parse_type(t_recipe *recipe, const char **print_me);
int					parse_length(t_recipe *recipe, const char **print_me);
int					print(va_list *arguments, t_recipe recipe);
int					print_char(va_list *arguments, t_recipe recipe);
void				write_padding(char padding_char, int len);
int					count_num_length(long long int num, int base,
t_recipe recipe);
int					print_hex(va_list *arguments, t_recipe recipe);
unsigned long long	deal_with_length(va_list *arguments,
t_recipe recipe);
char				*handle_conversion(unsigned long long num,
t_recipe recipe);
void				deal_with_prefix(t_recipe *recipe,
unsigned long long num);
int					print_d_i_u(va_list *arguments, t_recipe recipe);
long long			deal_with_length_signed(va_list *arguments,
t_recipe recipe);
unsigned long long	deal_with_length_unsigned(va_list *arguments,
t_recipe recipe);
unsigned long long	handle_length_specifier(va_list *arguments,
t_recipe recipe);
int					print_percent(t_recipe recipe);
int					print_ptr(va_list *arguments, t_recipe recipe);
int					print_str(va_list *arguments, t_recipe recipe);

#endif
