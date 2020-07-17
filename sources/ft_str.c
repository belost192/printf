/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:05:12 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/17 20:37:17 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_option_putstr(char *str, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_write_right_left(flags.dot, len, 0);
		count += ft_putstr(str, flags.dot);
	}
	else
		count += ft_putstr(str, len);
	return (count);
}

int	ft_str(char *str, t_flags flags)
{

	size_t len;
	int count;
	char *copy_str;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	copy_str = ft_strdup(str);
	if (flags.dot >= 0 && (size_t)flags.dot > len)
		flags.dot = len;
	if (flags.minus == 1)
		count += ft_option_putstr(copy_str, flags, len);
	if (flags.dot >= 0)
		count += ft_write_right_left(flags.width, flags.dot, 0);
	else
		ft_write_right_left(flags.width, len, 0);

	if (flags.minus == 0)
		count += ft_option_putstr(copy_str, flags, len);
	return (count);
}
