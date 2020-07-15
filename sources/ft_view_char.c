/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:57:49 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/13 18:12:36 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_view_char(int c, t_flags flags)
{
	int count;

	count = 0;
	if (flags.minus == 1)
	{
		count += ft_putchar(c);
		ft_write_right_left(flags.width, flags.width, 0, 1, 0);
	}
	else
	{
		ft_write_right_left(flags.width, flags.width, 0, 1, 0);
		count += ft_putchar(c);
	}

	return (count);
}
