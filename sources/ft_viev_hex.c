/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viev_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:18:37 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/08 19:16:07 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	char *ft_nbr_hex(unsigned long long d_nbr, char *str, int count)
{
	while(d_nbr != 0)
	{
		if ((d_nbr % 16) < 10)
			str[count - 1] = (d_nbr % 16) + 48;
		else
			str[count - 1] = (d_nbr % 16) + 55;
		d_nbr /= 16;
		count--;
	}
	return (str);
}

char	*ft_nbr_to_hex(unsigned long long nbr)
{
	char	*str;
	int		count;
	unsigned long long d_nbr;

	count = 0;
	d_nbr = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while(nbr != 0)
	{
		nbr /= 16;
		count++;
	}
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (0);
	str[count] = '\0';
	str = ft_nbr_hex(d_nbr, str, count);
	return (str);
}

int	ft_viev_hex(int nbr, int upper)
{
	int		count;
	char 	*hex;
	int		len;

	count = 0;
	if	(upper == 1)
		nbr = ft_tolower(nbr);
	hex = ft_nbr_to_hex(nbr);
	len = ft_strlen(hex);
	count += ft_putstr(hex, len);
	return(count);
}
