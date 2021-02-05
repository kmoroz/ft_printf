/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_percent.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/04 18:58:48 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/04 19:09:13 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_percent(t_recipe recipe)
{
	if (recipe.width && !recipe.minus_flag)
	{
		if (recipe.zero_flag)
			write_padding('0', recipe.width--);
		else
			write_padding(' ', recipe.width--);
	}
	write_padding('%', 1);
	if (recipe.width && recipe.minus_flag)
		write_padding(' ', recipe.width--);
	if (recipe.width)
		return (recipe.width);
	return (1);
}
