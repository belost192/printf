/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:57:49 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/11 23:05:41 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_view_char(int c, t_flags flags)
{
	int count;

	count = 0;
	if(flags.flag_minus == 1)
	{
		ft_write_right(flags.width, 1);
	}
	count += ft_putchar(c);
	return (count);
}
