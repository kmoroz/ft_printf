/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_type.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 17:28:58 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/09 17:43:02 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	parse_type(t_recipe *recipe, const char **print_me)
{
	if (**print_me == 'c' || **print_me == 's' || **print_me == 'p' ||
	**print_me == 'd' || **print_me == 'i' || **print_me == 'u' ||
	**print_me == 'x' || **print_me == 'X' || **print_me == '%')
	{
		recipe->type = **print_me;
		(*print_me)++;
		return (1);
	}
	return (0);
}
