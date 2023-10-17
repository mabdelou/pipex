/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:20:33 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/04 17:20:36 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/header_bonus.h"

void	close_fds(t_node *node)
{
	int	a;

	a = -1;
	while (++a < (node->argc - 4) * 2)
		close(node->fds[a]);
}

void	close_fd(t_node *node)
{
	int	a;

	a = -1;
	while (++a < (node->argc - 4) * 2)
		close(node->fd[a]);
}
