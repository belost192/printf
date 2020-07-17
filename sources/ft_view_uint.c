/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <chnikia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 00:55:11 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/17 17:46:15 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_view_uint(unsigned int nbr)
{
	int		count;
	char	*str;
	int		len;

	count = 0;
	str = ft_unsigned_itoa(nbr, 10);
	len = ft_strlen(str);
	count += ft_putstr(str, len);
	return (count);
}
