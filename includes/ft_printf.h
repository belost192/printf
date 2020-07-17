/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:31:17 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/17 19:00:32 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "../libft/libft.h"
# include "stdarg.h"
# include "stdio.h"

typedef struct s_flags
{
    int minus;
    int zero;
    int star;
    int dot;
    int width;
    int type;
}              t_flags;

int	    ft_what_is_it(int c, t_flags flags, va_list av);
int		ft_valid_type(int c);

int		ft_printf(const char *str, ...);
int		ft_viev_input(const char *input, va_list av);

int		ft_view_int(int nbr, t_flags flags);
int 	ft_view_char(int c, t_flags flags);
int		ft_str(char *str, t_flags flags);
int		ft_view_uint(unsigned int nbr);
int		ft_viev_hex(int nbr, int upper);
int	    ft_viev_scan(int i, va_list av, t_flags *flags,const char *input);
t_flags ft_viev_digit(char width, t_flags flags);

int		ft_putchar(int c);
int		ft_putstr(char *str, int len);
int     ft_write_right_left(int width, int minus, int zero);
char	*ft_unsigned_itoa(unsigned long long nbr, int base);
char	*ft_nbr_to_hex(unsigned long long nbr);

t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flag_star(va_list av, t_flags flags);
t_flags	ft_flag_width(t_flags flags, va_list av);
int	    ft_flags(int c);
t_flags	ft_flag_digit(char c, t_flags flags);
int					ft_flag_dot(const char *input, int start, t_flags *flags,
								va_list av);

#endif
