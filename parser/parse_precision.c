/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_precision.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 17:26:04 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/05 18:25:08 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"

int	parse_precision(va_list *arguments, t_recipe *recipe, const char **print_me)
{
	if (**print_me == '.')
	{
		(*print_me)++;
		if (ft_isalpha(**print_me))
			recipe->null_precision = 1;
		if (**print_me == '*')
		{
			recipe->precision = va_arg(*arguments, int);
			if (recipe->precision == 0)
				recipe->null_precision = 1;
			(*print_me)++;
		}
		while (ft_isdigit(**print_me))
		{
			recipe->precision = (recipe->precision * 10) + (**print_me - '0');
			if (recipe->precision == 0)
				recipe->null_precision = 1;
			(*print_me)++;
		}
		return (1);
	}
	return (0);
}
