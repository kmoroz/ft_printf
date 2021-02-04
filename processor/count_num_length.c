/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   count_num_length.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 17:41:33 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/04 10:09:48 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int						count_num_length(long long int num, int base,
t_recipe recipe)
{
	int count;

	count = 0;
	if (recipe.null_precision && !num)
		return (0);
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = num * -1;
		count++;
	}
	while (num)
	{
		num = num / base;
		count++;
	}
	return (count);
}
