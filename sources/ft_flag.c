/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:52:42 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/13 15:20:15 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags	ft_viev_digit(char width, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (width - 48);
	return (flags);
}

t_flags	ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags	ft_flag_star(va_list av, t_flags flags)
{
	flags.width = va_arg(av, int);

	if (flags.width < 0)
		flags.width *= -1;
	return (flags);
}

int	ft_flag_dot(va_list av, t_flags *flags, const char *input, int i)
{
	if (input[++i] == '*')
		flags->dot = va_arg(av, int);
	else
	{
		flags->dot = 0;
		while (ft_isdigit(input[i]))
		{
			flags->dot = (flags->dot * 10) + (input[i] - 48);
			i++;
		}

	}
return (i);
}
