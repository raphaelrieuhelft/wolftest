/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgallois <marvin@42.fd>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:32:07 by vgallois          #+#    #+#             */
/*   Updated: 2016/12/03 23:29:54 by vgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static size_t	digit_count(long n)
{
	size_t i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	v;
	size_t	count;
	char	*str;
	char	neg;

	v = n;
	neg = (v < 0 ? 1 : 0);
	count = digit_count(v);
	str = ft_strnew(count + neg);
	if (str == NULL)
		return (NULL);
	if (neg)
	{
		v = -v;
		str[0] = '-';
	}
	while (count > 0)
	{
		str[count + neg - 1] = (v % 10) + '0';
		count--;
		v /= 10;
	}
	return (str);
}
