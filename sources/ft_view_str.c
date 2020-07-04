/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chnikia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 21:05:12 by chnikia           #+#    #+#             */
/*   Updated: 2020/07/04 21:11:09 by chnikia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_view_str(char *str)
{
	int len;
	int count;

	len = ft_strlen(str);
	count = 0;
	count += ft_putstr(str, len);
	return (count);
}
