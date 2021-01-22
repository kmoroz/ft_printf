/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:54:43 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/22 17:48:45 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"
#include <stdio.h> //remove later

int	ft_isdigit(int argument)
{
	if (argument >= '0' && argument <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int count;
	int strtonum;
	int isnegativenum;

	count = 0;
	strtonum = 0;
	isnegativenum = 1;
	while (str[count] == ' ' || str[count] == '\n' || str[count] == '\f'
	|| str[count] == '\r' || str[count] == '\t' || str[count] == '\v')
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			isnegativenum = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		strtonum = 10 * strtonum + (str[count] - '0');
		count++;
	}
	if (isnegativenum == -1)
		strtonum = strtonum * -1;
	return (strtonum);
}

void	initialise_struct(t_recipe *recipe)
{
	recipe->minus_flag = 0;
	recipe->zero_flag = 0;
	recipe->space_flag = 0;
	recipe->plus_flag = 0;
	recipe->hash_flag = 0;
	recipe->width = 0;
	recipe->precision = 0;
	recipe->type = '\0';
	recipe->length = 0;
}

int get_length()
{

}

char	parse_type(t_recipe *recipe, const char **print_me)
{
	if (**print_me == 'c' || **print_me == 's' || **print_me == 'p' ||
	**print_me == 'd' || **print_me == 'i' || **print_me == 'u' ||
	**print_me == 'x' || **print_me == 'X' || **print_me == '%' ||
	**print_me == 'n' || **print_me == 'f' || **print_me == 'g' ||
	**print_me == 'e')
	{
		recipe->type = **print_me;
		(*print_me)++;
		return (1);
	}
	return (0);
}

int	parse_width(va_list *arguments, t_recipe *recipe, const char **print_me)
{
	int		width;

	width = 0;
	if (**print_me == '*')
	{
		width = va_arg(*arguments, int);
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

int	parse_flag(t_recipe *recipe, const char **print_me)
{
	(*print_me)++;
	if (**print_me == '+')
	{
		recipe->plus_flag = 1;
		return (1);
	}
	if (**print_me == '-')
	{
		recipe->minus_flag = 1;
		return (1);
	}
	if (**print_me == '0')
	{
		recipe->zero_flag = 1;
		return (1);
	}
	if (**print_me == ' ')
	{
		recipe->space_flag = 1;
		return (1);
	}
	if (**print_me == '#')
	{
		recipe->hash_flag = 1;
		return (1);
	}
	return (0);
}

int	parse(va_list *arguments, const char **print_me)
{
	t_recipe recipe;

	initialise_struct(&recipe);
	while ("the prophecy is real")
	{
		if (parse_flag(&recipe, print_me))
			continue;
		parse_width(arguments, &recipe, print_me);
		parse_precision(arguments, &recipe, print_me);
		parse_type(&recipe, print_me);
		break ;
	}
	if (!recipe.type)
		return (-1);
}

int	count_till_percent(const char *print_me)
{
	int length;

	length = 0;
	while (*print_me != '%')
	{
		length++;
		print_me++;
	}
	return (length);
}

int	ft_printf(const char *print_me, ...)
{
	va_list arguments;
	int		length_till_percent;

	length_till_percent = count_till_percent(print_me);
	va_start(arguments, print_me);
	while (*print_me)
	{
		write(1, print_me, length_till_percent);
		print_me = print_me + length_till_percent;
		parse(&arguments, &print_me);
	}
	va_end(arguments);
}

int	main()
{
	double e;
	e= 2.718281828;
	//printf("poo %+-5.1f", e);  //poo +2.7
	ft_printf("poo %+-*.*f", 5, 1, e);
}
