/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:06:38 by csnowbal          #+#    #+#             */
/*   Updated: 2020/07/04 21:15:48 by chnikia          ###   ########.fr       */
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
	printf("Now %d year\n", x);
	ft_printf("Now %d year\n", x);
	printf("Now %s year\n", str);
	ft_printf("Now %s year\n", str);
	printf("Now %c year\n", c);
	ft_printf("Now %c year\n", c);
	return (0);
}
