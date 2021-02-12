/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d_i_u.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:03:38 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/12 16:01:25 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

static void	deal_with_left_pads(t_recipe recipe, long long num,
int num_length, char **converted_number)
{
	int padding_len;

	padding_len = count_padding_len(recipe, num_length, num);
	if (recipe.width && !recipe.minus_flag)
	{
		if (recipe.zero_flag)
		{
			if (num < 0)
			{
				write(1, "-", 1);
				(*converted_number)++;
			}
			if (recipe.plus_flag)
				write(1, "+", 1);
			if (recipe.space_flag)
				write(1, " ", 1);
			write_padding('0', padding_len);
		}
		else
			write_padding(' ', padding_len);
	}
}

static void	write_number(char *converted_num, long long num,
int num_length, t_recipe recipe)
{
	if (*converted_num == '-')
	{
		write(1, "-", 1);
		num_length--;
		converted_num++;
	}
	if (num < 0 && recipe.zero_flag && recipe.width && !recipe.minus_flag)
		num_length--;
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

static void	check_recipe(t_recipe *recipe, long long num)
{
	if (recipe->space_flag && recipe->plus_flag)
		recipe->space_flag = 0;
	if (recipe->precision > 0 || recipe->null_precision)
		recipe->zero_flag = 0;
	if (num < 0)
	{
		recipe->plus_flag = 0;
		recipe->space_flag = 0;
	}
}

static int	calculate_return(t_recipe recipe, int num_length, long long num)
{
	if (recipe.width >= num_length && recipe.width > recipe.precision)
		return (recipe.width);
	if (recipe.precision >= num_length && num >= 0)
		return (recipe.precision);
	if (recipe.precision >= num_length && num < 0)
		return (recipe.precision + 1);
	return (num_length + recipe.plus_flag + recipe.space_flag);
}

int			print_d_i_u(va_list *arguments, t_recipe recipe)
{
	long long int	num;
	int				num_length;
	char			*converted_number;
	char			*temp;
	int				padding_len;

	num = handle_length_specifier(arguments, recipe);
	check_recipe(&recipe, num);
	num_length = count_num_length(num, 10, recipe);
	padding_len = count_padding_len(recipe, num_length, num);
	converted_number = ft_itoa_base(num, 10, "0123456789");
	if (!converted_number)
		return (-1);
	temp = converted_number;
	deal_with_left_pads(recipe, num, num_length, &converted_number);
	write_number(converted_number, num, num_length, recipe);
	if (recipe.width && recipe.minus_flag)
		write_padding(' ', padding_len);
	free(temp);
	return (calculate_return(recipe, num_length, num));
}
