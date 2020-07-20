/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_is_it.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:20:06 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/20 22:42:47 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_valid_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

static int	ft_type_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar('%');
	count = ft_write_right_left(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_putchar('%');
	return (count + 1);
}

int	ft_what_is_it(int c, t_flags flags, va_list av)
{
	int count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_type_int(va_arg(av, int), flags);
	else if (c == 'c')
		count += ft_type_char(va_arg(av, int), flags);
	else if (c == 's')
		count += ft_type_str(va_arg(av, char *), flags);
	else if (c == 'u')
		count += ft_type_uint((unsigned int)va_arg(av, unsigned int), flags);
	else if (c == '%')
		count += ft_type_percent(flags);
	else if (c == 'x')
		count += ft_type_hex(va_arg(av, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_type_hex(va_arg(av, unsigned int), 0, flags);
	else if (c == 'p')
		count += ft_type_ptr(va_arg(av, unsigned long long), flags);
	return (count);
}

