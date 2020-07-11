/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 13:31:17 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/11 23:46:56 by chnikia          ###   ########.fr       */
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

int		ft_what_is_it(int c, va_list av, t_flags flags);
int		ft_valid_type(int c);

int		ft_printf(const char *str, ...);
int		ft_viev_input(const char *input, va_list av);

int		ft_view_int(int nbr);
int 	ft_view_char(int c, t_flags flags);
int		ft_view_str(char *str);
int		ft_view_uint(unsigned int nbr);
int		ft_viev_hex(int nbr, int upper);
int	    ft_viev_scan(int i, va_list av, t_flags *flags, char *input);
t_flags ft_viev_digit(char width, t_flags *flags);

int		ft_putchar(int c);
int		ft_putstr(char *str, int len);
int     ft_write_right(int wigth, int minus);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_nbr_to_hex(unsigned long long nbr);
t_flags	ft_flag_minus(t_flags flags);


#endif
