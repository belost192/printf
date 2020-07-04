/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:45:37 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/04 20:52:58 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_view_int(int nbr)
{
	char *my_nbr;
	int count;
	size_t len;

	count = 0;
	my_nbr = ft_itoa(nbr);
	len = ft_strlen(my_nbr);
	count += ft_putstr(my_nbr, len);
return (count);
}
