/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nngwenya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:18:51 by nngwenya          #+#    #+#             */
/*   Updated: 2017/08/17 16:52:41 by nngwenya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *str, char c)
{
	int words;
	int i;
	int bul;

	bul = 0;
	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && bul == 0)
		{
			words++;
			bul = 1;
		}
		if (str[i] == c && bul == 1)
			bul = 0;
		i++;
	}
	return (words);
}

static char	*get_word(char const *str, char c)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	ret = (char*)malloc(sizeof(ret) * (i + 1));
	if (!ret)
		return (NULL);
	ret[i] = 0;
	i = 0;
	while (str[i] && str[i] != c)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**ret;
	int		bul;
	int		i;
	int		x;

	if (!str || !(i = -1))
		return (NULL);
	x = countwords(str, c);
	if (!(ret = (char **)malloc(sizeof(ret) * (x + 1))))
		return (NULL);
	ret[x] = 0;
	x = 0;
	bul = 0;
	while (str[++i])
	{
		if (str[i] != c && bul == 0)
		{
			ret[x] = get_word(&str[i], c);
			bul = 1;
			x++;
		}
		if (str[i] == c && bul == 1)
			bul = 0;
	}
	return (ret);
}
