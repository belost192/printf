/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:18:37 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/20 20:40:17 by chnikia          ###   ########.fr       */
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
static int	ft_output(char *hex, t_flags flags, size_t len)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_write_right_left(flags.dot - 1, len - 1, 1);
	count += ft_putstr(hex, len);
	return (count);
}
static int	ft_put(char *hex, t_flags flags)
{
	const size_t	len = ft_strlen(hex);
	int				count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output(hex, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_write_right_left(flags.width, 0, 0);
	}
	else
		count += ft_write_right_left(flags.width,
		len, flags.zero);
	if (flags.minus == 0)
		count += ft_output(hex, flags, len);
	return (count);
}

int	ft_type_hex(unsigned int nbr, int x, t_flags flags)
{
	int		count;
	char 	*hex;

	count = 0;
	nbr = (unsigned int)(4294967295 + 1 + nbr);
	if (flags.dot == 0 && nbr == 0)
	{
		count += ft_write_right_left(flags.width, 0, 0);
		return (count);
	}
	hex = ft_nbr_to_hex((unsigned long long)nbr);
	if	(x == 1)
		hex = ft_str_tolower(hex);
	count += ft_put(hex, flags);
	free(hex);
	return(count);
}
