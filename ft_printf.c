/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 13:54:43 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/26 17:11:36 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h> //remove later

/*
** int	ft_isdigit(int argument)
** {
** 	if (argument >= '0' && argument <= '9')
** 		return (1);
** 	return (0);
** }
*/

size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
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

int		parse_length(t_recipe *recipe, const char **print_me)
{
	if (**print_me == 'l' || **print_me == 'h')
	{
		recipe->length = **print_me;
		(*print_me)++;
		return (1);
	}
	return (0);
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

void write_padding(char padding_char, int len)
{
	while (len > 0){
		write(1, &padding_char, 1);
		len--;
	}
}

void	print_char(va_list *arguments, t_recipe recipe)
{
	wchar_t	c;

	if (recipe.length == 'l')
		c = va_arg(*arguments, wchar_t);
	else
		c = (char)va_arg(*arguments, int);
	if (recipe.width && !recipe.minus_flag)
	{
		if (recipe.zero_flag)
			write_padding('0', recipe.width - 1);
		else
			write_padding(' ', recipe.width - 1);
	}
	write(1, &c, 1);
	if (recipe.width && recipe.minus_flag)
		write_padding(' ', recipe.width - 1);
}

void	print(va_list *arguments, t_recipe recipe)
{
	if (recipe.type == 'c')
		print_char(arguments, recipe);
}

int	count_till_percent(const char *print_me)
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

int	ft_printf(const char *print_me, ...)
{
	va_list		arguments;
	int			length_till_percent;
	t_recipe	recipe;

	initialise_struct(&recipe);
	va_start(arguments, print_me);
	while (*print_me)
	{
		length_till_percent = count_till_percent(print_me);
		write(1, print_me, length_till_percent);
		print_me = print_me + length_till_percent;
		if (*print_me)
		{
			parse(&arguments, &print_me, &recipe);
			print(&arguments, recipe);
		}
	}
	va_end(arguments);
	return (1);
}
