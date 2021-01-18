/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 14:07:39 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/18 14:49:28 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_flags
{
	int			left_justify_minus;
	int			right_justify_num;
	int			zero_padding;
	int			precision_dot;
	int			conversion;
}				t_flags;

int	ft_printf(const char *print_me, ...);

#endif