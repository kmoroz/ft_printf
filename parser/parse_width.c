/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_width.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 17:27:04 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/08 14:26:19 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	parse_width(va_list *arguments, t_recipe *recipe, const char **print_me)
{
	int		width;

	width = 0;
	if (**print_me == '*')
	{
		width = va_arg(*arguments, int);
		if (width < 0)
		{
			recipe->minus_flag = 1;
			width = width * -1;
		}
		(*print_me)++;
	}
	while (ft_isdigit(**print_me))
	{
		width = (width * 10) + (**print_me - '0');
		(*print_me)++;
	}
	recipe->width = width;
	return (!width ? 0 : 1);
}
