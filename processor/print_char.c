/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_char.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 18:09:50 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/27 13:32:09 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stddef.h>
#include <unistd.h>

int	print_char(va_list *arguments, t_recipe recipe)
{
	wchar_t	c;

	if (recipe.length == 'l')
		c = va_arg(*arguments, wchar_t);
	else
		c = (char)va_arg(*arguments, int);
	if (recipe.width && !recipe.minus_flag)
		write_padding(' ', recipe.width - 1);
	write(1, &c, 1);
	if (recipe.width && recipe.minus_flag)
		write_padding(' ', recipe.width - 1);
	return (recipe.width ? recipe.width : 1);
}
