/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_precision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 17:26:04 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/26 18:05:26 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	parse_precision(va_list *arguments, t_recipe *recipe, const char **print_me)
{
	int precision;

	precision = 0;
	if (**print_me == '.')
	{
		(*print_me)++;
		if (**print_me == '*')
		{
			precision = va_arg(*arguments, int);
			(*print_me)++;
		}
		else if (ft_isdigit(**print_me))
		{
			precision = (precision * 10) + (**print_me - '0');
			(*print_me)++;
		}
		recipe->precision = precision;
		return (1);
	}
	return (0);
}
