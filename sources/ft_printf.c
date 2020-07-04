/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:40:07 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/04 21:25:09 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_viev_input(const char *input, va_list av)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] == '\0')
			return (-1);
		if (input[i] == '%' && ft_valid_type(input[i + 1]))
		{
			count += ft_what_is_it(input[i + 1], av);
			i++;
		}
		else if(input[i] != '%')
			ft_putchar(input[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int count;
	va_list av;
	const char *input;

	count = 0;
	input = ft_strdup(str);
	va_start(av, str);
	count += ft_viev_input(input, av);
	va_end(av);
	return(count);
}
