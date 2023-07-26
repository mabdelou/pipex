/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 21:36:15 by mabdelou          #+#    #+#             */
/*   Updated: 2021/11/16 14:13:38 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static	void	print_str(char a, int fd)
{
	write(fd, &a, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	b;

	if (s != NULL)
	{
		b = 0;
		while (s[b])
		{
			print_str(s[b], fd);
			b++;
		}
	}
}
