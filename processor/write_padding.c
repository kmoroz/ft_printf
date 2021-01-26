/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_padding.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 18:16:03 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/26 18:31:44 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_padding(char padding_char, int len)
{
	while (len > 0)
	{
		write(1, &padding_char, 1);
		len--;
	}
}
