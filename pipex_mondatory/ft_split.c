/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:56:02 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/15 21:27:37 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	int	words_number(char const *s, char c)
{
	int	a;
	int	nb;

	nb = 0;
	a = 0;
	while (s[a] && s[a] == c)
		a++;
	while (s[a])
	{
		if (s[a] != c && ((s[a + 1] == c) || s[a + 1] == '\0'))
			nb++;
		a++;
	}
	return (nb);
}

static	int	size_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	char	**fill_tab(char **tab, char const *s, char c, int nb_w)
{
	int	a;
	int	b;
	int	d;
	int	size_w;

	b = 0;
	a = -1;
	while (++a < nb_w)
	{
		d = 0;
		while (s[b] && s[b] == c)
		b++;
		if (s[b] && s[b] != c)
		{
			size_w = size_word(&s[b], c);
			tab[a] = malloc(sizeof(char) * (size_w + 1));
			if (!tab)
				return (NULL);
			while (s[b] && s[b] != c)
				tab[a][d++] = s[b++];
			tab[a][d] = '\0';
		}
	}
	tab[++a] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_w;

	if (s == NULL)
		return (NULL);
	nb_w = words_number(s, c);
	tab = malloc(sizeof(char *) * (nb_w + 2));
	if (!tab)
		return (NULL);
	tab[nb_w] = NULL;
	tab = fill_tab(tab, s, c, nb_w);
	return (tab);
}
