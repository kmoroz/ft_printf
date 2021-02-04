/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 10:38:22 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/04 10:37:59 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	count_converted_num_length(long long int number, int base)
{
	int count;

	count = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = number * -1;
		count++;
	}
	while (number)
	{
		number = number / base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(long long int number, int base, char *digits_str)
{
	char	*conversion;
	int		num_length;

	num_length = count_converted_num_length(number, base);
	conversion = (char*)malloc(num_length + 1);
	if (!conversion)
		return (NULL);
	conversion[num_length] = '\0';
	if (number == 0)
	{
		conversion[0] = '0';
		return (conversion);
	}
	if (number < 0 && base == 10)
	{
		conversion[0] = '-';
		number = number * -1;
	}
	while (number)
	{
		num_length--;
		conversion[num_length] = digits_str[number % base];
		number = number / base;
	}
	return (conversion);
}
