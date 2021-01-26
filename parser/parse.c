/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 17:21:12 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/26 17:29:18 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	parse(va_list *arguments, const char **print_me, t_recipe *recipe)
{
	while ("the prophecy is real")
	{
		if (parse_flag(recipe, print_me))
			continue;
		parse_width(arguments, recipe, print_me);
		parse_precision(arguments, recipe, print_me);
		parse_length(recipe, print_me);
		parse_type(recipe, print_me);
		break ;
	}
	if (!recipe->type)
		return (0);
	return (1);
}
