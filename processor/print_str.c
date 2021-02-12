/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_str.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/05 14:10:53 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/12 12:07:59 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>

static void	deal_with_left_pads(int *str_len, t_recipe recipe)
{
	if (recipe.precision > *str_len)
		write_padding(' ', recipe.width - *str_len);
	if (recipe.precision > 0 && recipe.precision <= *str_len)
	{
		write_padding(' ', recipe.width - recipe.precision);
		*str_len = recipe.precision;
	}
	if (recipe.null_precision)
		write_padding(' ', recipe.width);
	if (recipe.precision <= 0 && recipe.width && !recipe.null_precision)
		write_padding(' ', recipe.width - *str_len);
}

static void	deal_with_precision(int *str_len, t_recipe recipe)
{
	if (recipe.precision > 0 && recipe.precision <= *str_len)
		*str_len = recipe.precision;
}

static void	deal_with_right_pads(int *str_len, t_recipe recipe)
{
	if (recipe.null_precision)
		write_padding(' ', recipe.width);
	else
		write_padding(' ', recipe.width - *str_len);
}

int			print_str(va_list *arguments, t_recipe recipe)
{
	char	*str;
	int		str_len;

	str = va_arg(*arguments, char*);
	if (str == NULL)
		str = "(null)";
	str_len = (int)ft_strlen(str);
	if (recipe.width && !recipe.minus_flag)
		deal_with_left_pads(&str_len, recipe);
	if (recipe.precision)
		deal_with_precision(&str_len, recipe);
	if (!recipe.null_precision)
		write(1, str, str_len);
	if (recipe.width && recipe.minus_flag)
		deal_with_right_pads(&str_len, recipe);
	if (recipe.width && (recipe.width >= str_len || recipe.null_precision))
		return (recipe.width);
	if (recipe.null_precision)
		return (0);
	return (str_len);
}
