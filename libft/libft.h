/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ksmorozo <ksmorozo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/10 11:43:49 by ksmorozo      #+#    #+#                 */
/*   Updated: 2021/02/03 12:10:58 by ksmorozo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

int		ft_isdigit(int argument);
int		ft_isalpha(int argument);
char	*ft_itoa_base(unsigned long long int number,
int base, char *digits_str);

#endif
