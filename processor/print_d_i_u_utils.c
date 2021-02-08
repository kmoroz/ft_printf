/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_d_i_u_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/08 14:44:59 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/08 14:47:51 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
