/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:06:38 by csnowbal          #+#    #+#             */
/*   Updated: 2020/07/14 21:37:46 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int x;
	char c;
	char *str;
	str = "Happy New";
	c = 'x';
	x = 2020;
/*	printf("Now %d year\n", x);
	ft_printf("Now %d year\n", x);
	printf("Now %s year\n", str);
	ft_printf("Now %s year\n", str);
	printf("Now %c year\n", c);
	ft_printf("Now %c year\n", c);
	printf("Now %u year\n", x);
	ft_printf("Now %u year\n", x);
	printf("Now %x year\n", x);
	ft_printf("Now %x year\n", x);
	printf("Now %X year\n", x);
	ft_printf("Now %X year\n", x);
	printf("Now %-5c year\n", c);
	ft_printf("Now %-5c year\n", c);
	printf("Now %5c year\n", c);
	ft_printf("Now %5c year\n", c);
	printf("Now %*c year\n",4 ,c);
	ft_printf("Now %*c year\n",4 ,c);

	printf("Now %d year\n", x);
	ft_printf("Now %d year\n\n", x);

	printf("Now %5d year\n", x);
	ft_printf("Now %5d year\n\n", x);

	printf("Now %10.5d year\n", x);
	ft_printf("Now %10.5d year\n\n", x);

	printf("Now %5.10d year\n", x);
	ft_printf("Now %5.10d year\n\n", x);*/

	printf("%13.5d year\n", x);
	ft_printf("%13.5d year\n\n", x);
	printf("%5.13d year\n", x);
	ft_printf("%5.13d year\n\n", x);
	printf("%-13.5dyear\n", x);
	ft_printf("%-13.5d year\n\n", x);

	return (0);
}
