/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 18:08:43 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/17 13:18:42 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print(va_list *arguments, t_recipe recipe)
{
	int result_length;

	result_length = 0;
	if (recipe.type == 'c')
		result_length = print_char(arguments, recipe);
	if (recipe.type == 'x')
		result_length = print_hex(arguments, recipe);
	if (recipe.type == 'X')
		result_length = print_hex(arguments, recipe);
	if (recipe.type == 'd')
		result_length = print_d_i(arguments, recipe);
	if (recipe.type == 'u')
		result_length = print_u(arguments, recipe);
	if (recipe.type == 'i')
		result_length = print_d_i(arguments, recipe);
	if (recipe.type == '%')
		result_length = print_percent(recipe);
	if (recipe.type == 'p')
		result_length = print_ptr(arguments, recipe);
	if (recipe.type == 's')
		result_length = print_str(arguments, recipe);
	return (result_length);
}
