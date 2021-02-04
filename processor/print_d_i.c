/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d_i.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 17:05:59 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/04 14:15:35 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include "unistd.h"

int		deal_with_length(va_list *arguments, t_recipe recipe)
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

void	write_number(long long num, char *converted_num,
int num_length, t_recipe recipe)
{
	if (*converted_num == '-')
	{
		write(1, "-", 1);
		num_length--;
		converted_num++;
	}
	if (recipe.plus_flag && (num < 0 && !recipe.zero_flag))
	{
		if (num < 0)
			write(1, "-", 1);
		else
			write(1, "+", 1);
	}
	if (recipe.space_flag)
		write(1, " ", 1);
	if (recipe.precision)
		write_padding('0', recipe.precision - num_length);
	write(1, converted_num, num_length);
}

int		print_d_i(va_list *arguments, t_recipe recipe)
{
	long long int	num;
	int				num_length;
	char			*converted_number;

	if (recipe.space_flag && recipe.plus_flag)
		recipe.space_flag = 0;
	if (recipe.precision)
		recipe.zero_flag = 0;
	num = deal_with_length(arguments, recipe);
	num_length = count_num_length(num, 10, recipe);
	if (recipe.space_flag || recipe.plus_flag ||
	(recipe.precision && recipe.precision > num_length))
	{
		recipe.width -= (recipe.precision + recipe.space_flag + recipe.plus_flag);
		if (num < 0)
			recipe.width--;
	}
	else
		recipe.width -= num_length;
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
			write_padding('0', recipe.width);
		}
		else
			write_padding(' ', recipe.width);
	}
	write_number(num, converted_number, num_length, recipe);
	if (recipe.width && recipe.minus_flag)
		write_padding(' ', recipe.width);
	return (num_length + recipe.space_flag + recipe.plus_flag + recipe.width);
}
