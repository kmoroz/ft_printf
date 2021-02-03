/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 11:06:51 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/03 12:23:52 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int						count_hex_length(unsigned long long int num,
t_recipe recipe)
{
	int count;

	count = 0;
	if (recipe.null_precision && !num)
		return (0);
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 16;
		count++;
	}
	return (count);
}

unsigned long long int	deal_with_length(va_list *arguments, t_recipe recipe)
{
	unsigned long long int num;

	if (recipe.length == 'l')
		num = (unsigned long)va_arg(*arguments, long);
	if (recipe.length == 'h')
		num = (unsigned short)va_arg(*arguments, int);
	if (recipe.length == 'L')
		num = va_arg(*arguments, long long);
	if (recipe.length == 'H')
		num = (unsigned char)va_arg(*arguments, int);
	if (!recipe.length)
		num = (unsigned int)va_arg(*arguments, int);
	return (num);
}

void					deal_with_prefix(t_recipe recipe)
{
	char	*hex_prefix;

	hex_prefix = "0x";
	if (recipe.hash_flag && !recipe.null_precision)
		write(1, hex_prefix, 2);
}

void					deal_with_left_pads(int num_length, t_recipe recipe)
{
	if (recipe.width && !recipe.minus_flag && !recipe.precision)
	{
		if (recipe.zero_flag)
			write_padding('0', recipe.width - num_length);
		else
			write_padding(' ', recipe.width - num_length);
	}
	if (recipe.width && !recipe.minus_flag && recipe.precision)
	{
		if (recipe.precision < 0)
			write_padding(' ', recipe.width);
		if (recipe.precision < num_length && recipe.precision > 0)
			write_padding(' ', recipe.width - num_length);
		if (recipe.precision > num_length && recipe.precision > 0)
			write_padding(' ', recipe.width - recipe.precision);
	}
}

void					deal_with_precision(int num_length, t_recipe recipe)
{
	if (recipe.precision)
	{
		if (num_length < recipe.precision)
			write_padding('0', recipe.precision - num_length);
	}
}

void					deal_with_right_pads(int num_length, t_recipe recipe)
{
	if (recipe.width && recipe.minus_flag && !recipe.precision)
		write_padding(' ', recipe.width - num_length);
	if (recipe.width && recipe.minus_flag && recipe.precision)
	{
		if (recipe.precision < 0)
			write_padding(' ', recipe.width);
		if (recipe.precision < num_length && recipe.precision > 0)
			write_padding(' ', recipe.width - num_length);
		if (recipe.precision > num_length && recipe.precision > 0)
			write_padding(' ', recipe.width - recipe.precision);
	}
}

int						calculate_amount_printed(unsigned long long int num,
int num_length, t_recipe recipe)
{
	int amount_printed;

	amount_printed = num_length;
	if (recipe.null_precision && !num)
		return (0);
	if (recipe.hash_flag)
	{
		amount_printed += 2;
		if (recipe.width >= recipe.precision && recipe.width > amount_printed)
			return (recipe.width);
		if (recipe.precision > amount_printed)
			return (recipe.precision);
		return (amount_printed);
	}
	if (recipe.width >= recipe.precision && recipe.width > amount_printed)
		return (recipe.width);
	if (recipe.precision > amount_printed)
		return (recipe.precision);
	return (amount_printed);
}

int						print_hex(va_list *arguments, t_recipe recipe)
{
	unsigned long long int	num;
	int						num_length;
	char					*converted_num;

	if (recipe.precision)
		recipe.zero_flag = 0;
	num = deal_with_length(arguments, recipe);
	num_length = count_hex_length(num, recipe);
	converted_num = ft_itoa_base(num, 16, "0123456789abcdef");
	if (!converted_num)
		return (-1);
	if (recipe.hash_flag && num)
	{
		recipe.width -= 2;
		if (recipe.zero_flag || recipe.width <= num_length)
		{
			deal_with_prefix(recipe);
			recipe.hash_flag = 0;
		}
	}
	deal_with_left_pads(num_length, recipe);
	if (recipe.hash_flag && num)
	{
		deal_with_prefix(recipe);
		recipe.hash_flag = 0;
	}
	deal_with_precision(num_length, recipe);
	if (recipe.hash_flag && num)
		deal_with_prefix(recipe);
	write(1, converted_num, num_length);
	deal_with_right_pads(num_length, recipe);
	free(converted_num);
	return (calculate_amount_printed(num, num_length, recipe));
}
