/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_flag.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 17:25:06 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/09 12:10:03 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	parse_flag(t_recipe *recipe, const char **print_me)
{
	(*print_me)++;
	while (**print_me == '+' || **print_me == '-' || **print_me == '0' ||
	**print_me == ' ' || **print_me == '#')
	{
		if (**print_me == '+')
			recipe->plus_flag = 1;
		if (**print_me == '-')
			recipe->minus_flag = 1;
		if (**print_me == '0')
			recipe->zero_flag = 1;
		if (**print_me == ' ')
			recipe->space_flag = 1;
		if (**print_me == '#')
			recipe->hash_flag = 1;
		return (1);
	}
	return (0);
}
