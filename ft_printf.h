/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 14:07:39 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/01/22 17:50:51 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct	s_recipe
{
	int			minus_flag;
	int			zero_flag;
	int			space_flag;
	int			plus_flag;
	int			hash_flag;
	int			width;
	int			precision;
	char		type;
	int			length;
}				t_recipe;

int				ft_printf(const char *print_me, ...);

#endif
