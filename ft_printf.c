/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:54:43 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/09 11:33:00 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

void	initialise_struct(t_recipe *recipe)
{
	recipe->minus_flag = 0;
	recipe->zero_flag = 0;
	recipe->space_flag = 0;
	recipe->plus_flag = 0;
	recipe->hash_flag = 0;
	recipe->width = 0;
	recipe->precision = 0;
	recipe->null_precision = 0;
	recipe->type = '\0';
	recipe->length = 0;
}

int		count_till_percent(const char *print_me)
{
	int length;

	length = 0;
	while (*print_me && *print_me != '%')
	{
		length++;
		print_me++;
	}
	return (length);
}

int		ft_printf(const char *print_me, ...)
{
	va_list		arguments;
	int			amount_printed;
	t_recipe	recipe;

	initialise_struct(&recipe);
	amount_printed = 0;
	va_start(arguments, print_me);
	while (*print_me)
	{
		initialise_struct(&recipe);
		amount_printed += count_till_percent(print_me);
		write(1, print_me, count_till_percent(print_me));
		print_me = print_me + count_till_percent(print_me);
		if (*print_me)
		{
			parse(&arguments, &print_me, &recipe);
			if (print(&arguments, recipe) == -1)
				return (-1);
			else
				amount_printed += print(&arguments, recipe);
		}
	}
	va_end(arguments);
	return (amount_printed);
}
