/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d_i_u.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:03:38 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/05 11:21:31 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

long long			deal_with_length_signed(va_list *arguments, t_recipe recipe)
{
	long long int num;

	if (recipe.length == 'l')
		num = (long)va_arg(*arguments, long);
	if (recipe.length == 'h')
		num = (short)va_arg(*arguments, int);
	if (recipe.length == 'L')
		num = va_arg(*arguments, long long);
	if (recipe.length == 'H')
		num = (char)va_arg(*arguments, int);
	if (!recipe.length)
		num = (int)va_arg(*arguments, int);
	return (num);
}

unsigned long long	deal_with_length_unsigned(va_list *arguments,
t_recipe recipe)
{
	unsigned long long num;

	if (recipe.length == 'l')
		num = (unsigned long)va_arg(*arguments, unsigned long);
	if (recipe.length == 'h')
		num = (unsigned short)va_arg(*arguments, unsigned int);
	if (recipe.length == 'L')
		num = va_arg(*arguments, unsigned long long);
	if (recipe.length == 'H')
		num = (unsigned char)va_arg(*arguments, unsigned int);
	if (!recipe.length)
		num = (unsigned int)va_arg(*arguments, unsigned int);
	return (num);
}

unsigned long long	handle_length_specifier(va_list *arguments, t_recipe recipe)
{
	if (recipe.type == 'd' || recipe.type == 'i')
		return (deal_with_length_signed(arguments, recipe));
	else
		return (deal_with_length_unsigned(arguments, recipe));
}

void	write_number(char *converted_num,
int num_length, t_recipe recipe)
{
	if (*converted_num == '-')
	{
		write(1, "-", 1);
		num_length--;
		converted_num++;
	}
	if (recipe.plus_flag && !recipe.zero_flag)
	{
		write(1, "+", 1);
	}
	if (recipe.space_flag && !recipe.zero_flag)
		write(1, " ", 1);
	if (recipe.precision)
		write_padding('0', recipe.precision - num_length);
	write(1, converted_num, num_length);
}

int		print_d_i_u(va_list *arguments, t_recipe recipe)
{
	long long int	num;
	int				num_length;
	char			*converted_number;

	if (recipe.space_flag && recipe.plus_flag)
		recipe.space_flag = 0;
	if (recipe.precision)
		recipe.zero_flag = 0;
	num = handle_length_specifier(arguments, recipe);
	if (num < 0)
	{
		recipe.plus_flag = 0;
		recipe.space_flag = 0;
	}
	num_length = count_num_length(num, 10, recipe);
	if (recipe.precision && recipe.precision > num_length)
	{
		recipe.width -= (recipe.precision + recipe.space_flag + recipe.plus_flag);
		if (num < 0)
			recipe.width--;
	}
	else
		recipe.width -= (num_length + recipe.plus_flag + recipe.space_flag);
	converted_number = ft_itoa_base(num, 10, "0123456789");
	if (recipe.width && !recipe.minus_flag)
	{
		if (recipe.zero_flag)
		{
			if (num < 0)
			{
				write(1, "-", 1);
				converted_number++;
				num_length--;
			}
			if (recipe.plus_flag)
				write(1, "+", 1);
			if (recipe.space_flag)
				write(1, " ", 1);
			write_padding('0', recipe.width);
		}
		else
			write_padding(' ', recipe.width);
	}
	write_number(converted_number, num_length, recipe);
	if (recipe.width && recipe.minus_flag)
		write_padding(' ', recipe.width);
	free(converted_number);
	return (num_length + recipe.space_flag + recipe.plus_flag + recipe.width);
}
