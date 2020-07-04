/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:31:17 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/03 15:37:11 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "../libft/libft.h"
# include "stdarg.h"

int		ft_what_is_it(int c, va_list av);
int		ft_valid_type(int c);

int		ft_prinf(const char *str, ...);
int		ft_viev_input(const char *input, va_list av);

int		ft_view_int(int nbr);

int		ft_putchar(int c);

#endif
