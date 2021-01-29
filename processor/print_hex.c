/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 11:06:51 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/29 17:46:54 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

int		count_hex_length(unsigned long num, t_recipe recipe)
{
	int count;

	count = 0;
	if (recipe.null_precision)
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

void	deal_with_left_pads(int num_length, t_recipe recipe)
{
	if (recipe.width && !recipe.minus_flag && !recipe.precision)
	{
		if (recipe.zero_flag)
		{
			if (recipe.hash_flag)
				write_padding('0', recipe.width - (num_length + 2));
			write_padding('0', recipe.width - num_length);
		}
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

void	deal_with_precision(int num_length, t_recipe recipe)
{
	if (recipe.precision)
	{
		if (num_length < recipe.precision)
			write_padding('0', recipe.precision - num_length);
	}
}

void	deal_with_right_pads(int num_length, t_recipe recipe)
{
	if (recipe.width && recipe.minus_flag && !recipe.precision)
	{
		if (recipe.hash_flag)
			write_padding(' ', recipe.width - (num_length + 2));
		else
			write_padding(' ', recipe.width - num_length);
	}
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

char	*ft_itoa_base(unsigned long num, int base, int num_length)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (num_length + 1));
	str[num_length] = '\0';
	while (num)
	{
		num_length--;
		if (num % base < 10)
			str[num_length] = num % base + '0';
		else
			str[num_length] = num % base + 'a' - 10;
		num = num / base;
	}
	if (num == 0 && num_length)
		str[0] = '0';
	return (str);
}

int		print_hex(va_list *arguments, t_recipe recipe)
{
	unsigned long 		num; //why so huge
	int					num_length;
	char				*converted_num;

	if (recipe.length == 'l')
		num = (unsigned long)va_arg(*arguments, long);
	if (recipe.length == 'h')
		num = (unsigned short)va_arg(*arguments, int);
	else
		num = (unsigned int)va_arg(*arguments, int); //why is it casted as an unsigned it
	num_length = count_hex_length(num, recipe);
	deal_with_left_pads(num_length, recipe);
	deal_with_precision(num_length, recipe);
	converted_num = ft_itoa_base(num, 16, num_length);
	if (!recipe.null_precision)
		write(1, converted_num, num_length);
	deal_with_right_pads(num_length, recipe);
	free(converted_num);
	return (1);
}
