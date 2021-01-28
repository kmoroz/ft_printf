/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 18:08:43 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/28 15:17:32 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print(va_list *arguments, t_recipe recipe)
{
	int result_length;

	if (recipe.type == 'c')
		result_length = print_char(arguments, recipe);
	if (recipe.type == 'x')
		print_hex(arguments, recipe);
	return (result_length);
}
