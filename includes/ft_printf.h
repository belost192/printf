/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:31:17 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/04 21:12:48 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "../libft/libft.h"
# include "stdarg.h"
# include "stdio.h"

int		ft_what_is_it(int c, va_list av);
int		ft_valid_type(int c);

int		ft_printf(const char *str, ...);
int		ft_viev_input(const char *input, va_list av);

int		ft_view_int(int nbr);
int 	ft_view_char(int c);
int		ft_view_str(char *str);

int		ft_putchar(int c);
int		ft_putstr(char *str, int len);

#endif
