/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 18:08:43 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/26 18:09:30 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print(va_list *arguments, t_recipe recipe)
{
	if (recipe.type == 'c')
		print_char(arguments, recipe);
}
