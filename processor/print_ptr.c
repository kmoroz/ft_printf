/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_ptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 11:11:03 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/17 15:03:25 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

int	print_ptr(va_list *arguments, t_recipe recipe)
{
	unsigned long long	address_arg;
	int					length;
	char				*address_str;

	address_arg = va_arg(*arguments, unsigned long long);
	address_str = ft_itoa_base(address_arg, 16, "0123456789abcdef");
	if (!address_str)
		return (-1);
	length = ft_strlen(address_str) + 2;
	if (recipe.null_precision && address_arg == 0)
		length = 2;
	if (recipe.width && !recipe.minus_flag)
		write_padding(' ', recipe.width - length);
	write(1, "0x", 2);
	write(1, address_str, length - 2);
	if (recipe.width && recipe.minus_flag)
		write_padding(' ', recipe.width - length);
	free(address_str);
	if (recipe.width && recipe.width >= length)
		return (recipe.width);
	return (length);
}
