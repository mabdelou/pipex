/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:43:26 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/09 14:52:33 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/header_bonus.h"

int	ft_strncmp(const char	*s1,	const char	*s2)
{
	size_t			b;
	unsigned char	*i;
	unsigned char	*k;

	if (!s1 || !s2)
	{
		write(1, "\n", 1);
		return (-1);
	}
	i = (unsigned char *)s1;
	k = (unsigned char *)s2;
	b = 0;
	while ((i[b] == k[b]) && k[b])
		b++;
	if (i[b] == '\n')
		return (i[b + 1] - k[b]);
	return (i[b] - k[b]);
}
/*
int main ()
{
    
    int a;
	int b;
	b = strncmp("abcdefgh","abcdefgh",8);
    a = ft_strncmp("abcdefgh","abcdefgh",8);
    printf("%d\t%d\n",a,b);
}
*/
