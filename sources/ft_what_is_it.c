/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_what_is_it.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 18:20:06 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/02 18:11:52 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_valid_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_what_is_it(int c, va_list av)
{
	int count;

	count = 0;
	if (c == 'd')
		count += ft_view_int(va_arg(av, int));
/*	else if (c == 'c')
		count += ft_view_char(va_arg(av, int));
	else if (c == 's')
		count += ft_view_str(va_arg(av, *char));
	else if (c == '%')
		count += ft_putchar('%');
*/	return (count);
}
