/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_length.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 17:28:24 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/02 13:20:01 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		parse_length(t_recipe *recipe, const char **print_me)
{
	if (**print_me == 'l' || **print_me == 'h')
	{
		recipe->length = **print_me;
		(*print_me)++;
		if (**print_me == 'l')
		{
			recipe->length = 'L';
			(*print_me)++;
		}
		if (**print_me == 'h')
		{
			recipe->length = 'H';
			(*print_me)++;
		}
		return (1);
	}
	return (0);
}
