/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:08:59 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/14 21:48:56 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *str, int len)
{
	int	count;

	count = 0;
	while (str[count] && count < len)
		ft_putchar(str[count++]);
	return (count);
}
static size_t	ft_nbrlen(long nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	size_t	i;
	size_t	size;
	char	*str;
	long	nbr;

	i = 0;
	nbr = n;
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbrlen(nbr, 10);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
		i++;
	}
	while (i < size--)
	{
		str[size] = (nbr % 10) + 48;
		nbr /= 10;
	}
	return (str);
}

int ft_write_right_left(int wigth, int dot, int len, int minus, int zero)
{
	int count;
	int otstyp;
	int lol;

	lol = zero;


	count = 0;
	otstyp = wigth - dot;
	if (dot > 1 && minus == 0)
	{
		while ((wigth - dot) > 0)
			{
			count += ft_putchar(' ');
			wigth--;
			}
		while((dot-- - len) > 0)
			count += ft_putchar('0');
	return (count);
	}
	else if (dot <= 0 && minus == 1)
	{
		while ((wigth-- - len)> 0)
			count += ft_putchar(' ');
	}
	return (count);
}
