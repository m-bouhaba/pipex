/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:46:58 by mbouhaba          #+#    #+#             */
/*   Updated: 2022/02/19 19:44:57 by mbouhaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	countword(char const *s, char c)
{
	int	x;
	int	i;
	int	count;

	x = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			x = 0;
		else if (x == 0)
		{
			x = 1;
			count++;
		}
		i++;
	}
	return (count);
}

int	countchar(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		if (s[i] != c)
			j++;
		i++;
	}
	return (j);
}

char	*ft_stock(char const *s, char c)
{
	char	*w;
	int		i;
	int		j;

	i = 0;
	j = countchar(s, c);
	w = malloc(sizeof(char) * j + 1);
	if (!w)
		return (NULL);
	while (s[i] != c && s[i] && j > 0)
	{
		w[i] = s[i];
		i++;
		j--;
	}
	w[i] = '\0';
	return (w);
}

char	**ft_split(char *s, char c)
{
	char	**w;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	w = malloc (sizeof(char *) * (countword(s, c) + 1));
	if (!w)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			w[j] = ft_stock(s + i, c);
			i += countchar(s + i, c);
			j++;
		}
	}
	w[j] = 0;
	return (w);
}
