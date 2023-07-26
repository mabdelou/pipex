/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:42:37 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/04 17:42:39 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	wait_pross(t_node *node)
{
	int	a;

	a = -1;
	while (++a < node->argc - 3)
		wait(NULL);
}

void	multi_pipe(t_node *node)
{
	node->a = -1;
	node->b = -3;
	node->c = -1;
	while (++node->a < node->argc - 3)
	{
		++node->b;
		node->c += 2;
		if (fork() == 0)
		{
			if (node->a == 0)
				ft_cmd7(node, node->argv, node->envp);
			else if (node->a > 0 && node->a < node->argc - 4)
				ft_cmd8(node, node->argv, node->envp);
			else if (node->a == node->argc - 4)
				ft_cmd9(node, node->argv, node->envp);
		}
	}
	close_fds(node);
	wait_pross(node);
}
