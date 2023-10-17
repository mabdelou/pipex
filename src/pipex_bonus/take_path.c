/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:42:43 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/15 17:42:45 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/header_bonus.h"

void	ft_argumment_error(int argc)
{
	if (argc < 5)
	{
		write(1, "too many argumment\n", 20);
		exit(1);
	}
}

int	ft_calc_size_of_paht(char **envp)
{
	int		a;
	int		b;

	a = -1;
	b = 0;
	while (envp[++a])
	{
		if (envp[a][0] == 'P' && envp[a][1] == 'A')
		{
			while (envp[a][b] != '\0')
				b++;
			break ;
		}
	}
	return (b - 5);
}

char	*ft_take_path(char **envp)
{
	char	*path;
	int		a;
	int		b;
	int		c;

	a = -1;
	b = -1;
	c = -1;
	path = malloc(sizeof(char) * (ft_calc_size_of_paht(envp) + 1));
	if (!path)
	{
		write(2, "ERROR IN PATH MALLOC :\n", 21);
		exit(1);
	}
	while (envp[++a])
	{
		if (envp[a][0] == 'P' && envp[a][1] == 'A')
		{
			while (envp[a][++b] != '\0')
				if (b > 4)
					path[++c] = envp[a][b];
				path[c + 1] = '\0';
		}
	}
	return (path);
}
