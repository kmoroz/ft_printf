/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_hex_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/09 10:43:08 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/09 10:49:48 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>
#include "../libft/libft.h"

unsigned long long		deal_with_length(va_list *arguments,
t_recipe recipe)
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

char					*handle_conversion(unsigned long long num,
t_recipe recipe)
{
	char *converted_num;

	if (recipe.type == 'x')
		converted_num = ft_itoa_base(num, 16, "0123456789abcdef");
	else
		converted_num = ft_itoa_base(num, 16, "0123456789ABCDEF");
	return (converted_num);
}

void					deal_with_prefix(t_recipe *recipe,
unsigned long long num)
{
	char	*hex_prefix;

	if (recipe->hash_flag && num)
	{
		if (recipe->type == 'x')
			hex_prefix = "0x";
		if (recipe->type == 'X')
			hex_prefix = "0X";
		if (recipe->hash_flag)
			write(1, hex_prefix, 2);
	}
	recipe->hash_flag = 0;
}
