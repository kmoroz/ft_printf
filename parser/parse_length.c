/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_length.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 17:28:24 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/26 17:29:34 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		parse_length(t_recipe *recipe, const char **print_me)
{
	if (**print_me == 'l' || **print_me == 'h')
	{
		recipe->length = **print_me;
		(*print_me)++;
		return (1);
	}
	return (0);
}
