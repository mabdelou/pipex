/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_some_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:22:30 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/04 17:22:33 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_do_some_malloc(t_node *node)
{
	node->fds = malloc(sizeof(int) * (node->argc - 4) * 2);
	node->arg_cmds = malloc(sizeof(char **) * (node->argc - 3));
}
