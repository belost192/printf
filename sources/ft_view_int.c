/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:45:37 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/14 21:47:03 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int ft_view_int(int nbr, t_flags flags)
{
	printf("%d flag.minus\n", flags.minus);
	printf("%d flag.zero\n", flags.zero);
	printf("%d flag.width\n", flags.width);
	printf("%d flag.star\n", flags.star);
	printf("%d flag.dot\n", flags.dot);
	printf("%d flag.type\n", flags.type);


	char *my_nbr;
	int count;
	size_t len;
	int otstyp;

	count = 0;
	otstyp = flags.width - flags.dot;
	my_nbr = ft_itoa(nbr);
	len = ft_strlen(my_nbr);
	if (flags.dot > 1 && flags.minus == 0)
	    ft_write_right_left(flags.width, flags.dot, len, 0, 1);
	if (flags.dot > 1 && flags.minus == 1)
	    ft_write_right_left(flags.width, flags.dot, len, 1, 1);
	if (flags.dot <= 0 && flags.minus == 1)
		{
		count += ft_putstr(my_nbr, len);
	    ft_write_right_left(flags.width, 0, len, 1, 0);
		return (count);
		}
	if (flags.dot < 0 && flags.minus == 1)
		{
		count += ft_putstr(my_nbr, len);
	    ft_write_right_left(flags.width, 0, len, 1, 0);
		return (count);
		}
	count += ft_putstr(my_nbr, len);
	if(flags.minus == 1)
		while ((flags.width-- - flags.dot) > 0)
			count += ft_putchar(' ');

// 	if(flags.minus == 1)
		// while (--otstyp)
			// count += ft_putchar(' ');
return (count);
}
