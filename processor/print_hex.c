/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 11:06:51 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/12 15:09:56 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static void	deal_with_left_pads(int num_length,
t_recipe *recipe)
{
	if (recipe->width && !recipe->minus_flag && recipe->precision <= 0)
	{
		if (recipe->zero_flag)
			write_padding('0', recipe->width - num_length);
		else
			write_padding(' ', recipe->width - num_length);
	}
	if (recipe->width && !recipe->minus_flag && recipe->precision)
	{
		if (recipe->precision <= num_length && recipe->precision > 0)
			write_padding(' ', recipe->width - num_length);
		if (recipe->precision > num_length && recipe->precision > 0)
			write_padding(' ', recipe->width - recipe->precision);
	}
}

static void	deal_with_precision(int num_length, t_recipe recipe)
{
	if (recipe.precision > 0)
	{
		if (num_length < recipe.precision)
			write_padding('0', recipe.precision - num_length);
	}
}

static void	deal_with_right_pads(int num_length,
t_recipe recipe)
{
	if (recipe.width && recipe.minus_flag && recipe.precision <= 0)
		write_padding(' ', recipe.width - num_length);
	if (recipe.width && recipe.minus_flag && recipe.precision > 0)
	{
		if (recipe.precision <= num_length && recipe.precision > 0)
			write_padding(' ', recipe.width - num_length);
		if (recipe.precision > num_length && recipe.precision > 0)
			write_padding(' ', recipe.width - recipe.precision);
	}
}

static int	calculate_amount_printed(unsigned long long int num,
int num_length, t_recipe recipe)
{
	int amount_printed;

	amount_printed = num_length;
	if (recipe.null_precision && !num)
		return (recipe.width);
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

int			print_hex(va_list *arguments, t_recipe recipe)
{
	unsigned long long int	num;
	int						num_length;
	char					*converted_num;

	if (recipe.precision > 0 || recipe.null_precision)
		recipe.zero_flag = 0;
	num = deal_with_length(arguments, recipe);
	num_length = count_num_length(num, 16, recipe);
	if (recipe.hash_flag && num)
		recipe.width -= 2;
	converted_num = handle_conversion(num, recipe);
	if (!converted_num)
		return (-1);
	if (recipe.zero_flag || recipe.width <= num_length)
		deal_with_prefix(&recipe, num);
	deal_with_left_pads(num_length, &recipe);
	deal_with_prefix(&recipe, num);
	deal_with_precision(num_length, recipe);
	deal_with_prefix(&recipe, num);
	write(1, converted_num, num_length);
	deal_with_right_pads(num_length, recipe);
	free(converted_num);
	return (calculate_amount_printed(num, num_length, recipe));
}
