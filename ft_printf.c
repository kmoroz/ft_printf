/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:54:43 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/10 16:58:02 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft/libft.h"

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
	recipe->length = '\0';
	recipe->type = '\0';
}

int		check_percent(const char *print_me)
{
	while (*print_me)
	{
		if (*print_me == '%')
			return (1);
		print_me++;
	}
	return (0);
}

int		print_till_percent(const char **print_me)
{
	int		length;
	char	*buff;

	length = 0;
	buff = (char*)*print_me;
	while (*buff)
	{
		if (*buff == '%')
		{
			write(1, *print_me, length);
			(*print_me) += length;
			return (length);
		}
		length++;
		buff++;
	}
	return (0);
}

int		ft_printf(const char *print_me, ...)
{
	va_list		arguments;
	int			amount_to_be_printed;
	t_recipe	recipe;
	int			print_return;

	va_start(arguments, print_me);
	while (check_percent(print_me))
	{
		initialise_struct(&recipe);
		amount_to_be_printed = print_till_percent(&print_me);
		if (!parse(&arguments, &print_me, &recipe))
			return (-1);
		print_return = print(&arguments, recipe);
		if (print_return < 0)
			return (-1);
		amount_to_be_printed += print_return;
	}
	if (*print_me)
	{
		write(1, print_me, ft_strlen(print_me));
		amount_to_be_printed += ft_strlen(print_me);
	}
	va_end(arguments);
	return (amount_to_be_printed);
}
