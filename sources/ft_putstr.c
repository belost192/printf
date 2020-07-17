/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:08:59 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/17 17:45:50 by chnikia          ###   ########.fr       */
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


char	*ft_unsigned_itoa(unsigned long long nbr, int base)
{
	unsigned long long	nbr_tmp;
	char				*str;
	size_t				len;

	len = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr_tmp != 0)
	{
		nbr_tmp /= base;
		len++;
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (nbr != 0)
	{
		str[len - 1] = (nbr % base) + (nbr % base > 9 ? 55 : 48);
		nbr /= base;
		len--;
	}
	return (str);
}

int	ft_write_right_left(int width, int minus, int zero)
{
	int	count;

	count = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		count++;
	}
	return (count);
}
