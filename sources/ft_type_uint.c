/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:55:11 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/19 14:39:15 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_output(char *hex, t_flags flags, size_t len)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_write_right_left(flags.dot - 1, len - 1, 1);
	count += ft_putstr(hex, len);
	return (count);
}
static int	ft_put(char *hex, t_flags flags)
{
	const size_t	len = ft_strlen(hex);
	int				count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output(hex, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_write_right_left(flags.width, 0, 0);
	}
	else
		count += ft_write_right_left(flags.width,
		len, flags.zero);
	if (flags.minus == 0)
		count += ft_output(hex, flags, len);
	return (count);
}

int	ft_type_uint(unsigned int nbr, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.dot == 0 && nbr == 0)
	{
		count += ft_write_right_left(flags.width, 0, 0);
		return (count);
	}
	str = ft_unsigned_itoa(nbr, 10);
	count += ft_put(str, flags);
	return (count);
}
