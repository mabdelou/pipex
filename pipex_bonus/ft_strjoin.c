/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:28:41 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/16 00:50:18 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_srjn2(char const *s2, int a, int c, char *arr)
{
	int	b;

	b = 0;
	arr[a + b] = '/';
	b++;
	while (s2[b - 1] != '\0' && b < c)
	{
		arr[a + b] = s2[b - 1];
		b++;
	}
	arr[a + b] = '\0';
	return (arr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		c;
	char	*arr;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	c = ft_strlen(s1) + ft_strlen(s2) + 1;
	a = 0;
	arr = (char *)malloc((c + 1) * sizeof(char));
	if (arr == NULL)
		return (0);
	while (s1[a] != '\0' && a < c)
	{
		arr[a] = s1[a];
		a++;
	}
	b = 0;
	return (ft_srjn2(s2, a, c, arr));
}
