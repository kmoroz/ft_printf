/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d_i_u_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 14:44:59 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/17 13:41:34 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
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

int					count_padding_len(t_recipe recipe, int num_length,
long long num)
{
	int padding_len;

	padding_len = recipe.width;
	if (num < 0 && recipe.precision == num_length)
		padding_len--;
	if (recipe.precision && recipe.precision > num_length)
	{
		padding_len -= (recipe.precision + recipe.space_flag
		+ recipe.plus_flag);
		if (num < 0)
			padding_len--;
	}
	else
		padding_len -= (num_length + recipe.plus_flag + recipe.space_flag);
	return (padding_len);
}

int					count_num_length_unsigned(unsigned long long number,
int base)
{
	int count;

	count = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number = number / base;
		count++;
	}
	return (count);
}

char				*ft_itoa_base_unsigned(unsigned long long number,
int base, char *digits_str)
{
	char	*conversion;
	int		num_length;

	num_length = count_num_length_unsigned(number, base);
	conversion = (char*)malloc(num_length + 1);
	if (!conversion)
		return (NULL);
	conversion[num_length] = '\0';
	if (number == 0)
	{
		conversion[0] = '0';
		return (conversion);
	}
	while (number)
	{
		num_length--;
		conversion[num_length] = digits_str[number % base];
		number = number / base;
	}
	return (conversion);
}
