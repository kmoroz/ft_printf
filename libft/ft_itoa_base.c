/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/03 10:38:22 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/03 12:08:59 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	count_converted_num_length(unsigned long long int number, int base)
{
	int count;

	count = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number = number / base;
		count++;
	}
	return (count);
}

char	*ft_itoa_base(unsigned long long int number, int base, char *digits_str)
{
	char	*conversion;
	int		num_length;

	num_length = count_converted_num_length(number, base);
	conversion = (char*)malloc(num_length + 1);
	if (!conversion)
		return (NULL);
	conversion[num_length] = '\0';
	while (number)
	{
		num_length--;
		if (number % base < 10)
			conversion[num_length] = number % base + '0';
		else
			conversion[num_length] = digits_str[number % base];
		number = number / base;
	}
	if (number == 0 && num_length)
		conversion[0] = '0';
	return (conversion);
}
