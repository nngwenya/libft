/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 10:41:53 by nngwenya          #+#    #+#             */
/*   Updated: 2017/08/17 16:56:23 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		int_len(int i)
{
	int len;

	len = 1;
	if (i < 0)
	{
		len++;
		i *= -1;
	}
	while (i >= 10)
	{
		len++;
		i = i / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = int_len(n);
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	len -= 1;
	while (n > 0)
	{
		str[len--] = (char)(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
