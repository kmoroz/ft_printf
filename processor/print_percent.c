/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_percent.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 18:58:48 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/05 10:12:28 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_percent(t_recipe recipe)
{
	if (recipe.width && !recipe.minus_flag)
	{
		if (recipe.zero_flag)
			write_padding('0', recipe.width - 1);
		else
			write_padding(' ', recipe.width - 1);
	}
	write_padding('%', 1);
	if (recipe.width && recipe.minus_flag)
		write_padding(' ', recipe.width - 1);
	if (recipe.width)
		return (recipe.width);
	return (1);
}
