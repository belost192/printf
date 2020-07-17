/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:40:07 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/17 19:40:53 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// '-' по правому краю
// 'int' ширина
// *
t_flags ft_init_flags(void)
{
t_flags flags;
flags.minus = 0;
flags.zero = 0;
flags.star = 0;
flags.dot = -1;
flags.type = 0;
flags.width = 0;
return (flags);
}


int	ft_viev_scan(int i, va_list av, t_flags *flags,const char *input)
{
	while (input[i])
	{
		if (!ft_isdigit(input[i]) && !ft_valid_type(input[i]) && !ft_flags(input[i]))
			break ;
		if (input[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (input[i] == '.')
			i = ft_flag_dot(input, i, flags, av);
		if (input[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (input[i] == '*')
			*flags = ft_flag_width(*flags, av);
		if (ft_isdigit(input[i]))
			*flags = ft_flag_digit(input[i], *flags);
		if (ft_valid_type(input[i]))
		{
			flags->type = input[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_viev_input(const char *input, va_list av)
{
	int	i;
	int count;
	t_flags flags; i = 0;
	count = 0;
	while (input[i])
	{
		flags = ft_init_flags();
		if (input[i] == '%' && input[i + 1] == '\0')
			return (-1);
		if (input[i] == '%' && input[i + 1])
			{
				i++;
				i = ft_viev_scan(i, av, &flags, input);
				if (ft_valid_type(input[i]))
				{
					count += ft_what_is_it((char)flags.type, flags, av);
				}
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

