/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:23:28 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/04 17:23:31 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/header_bonus.h"

void	fill_node(t_node *node, char **argv, char **envp, int argc)
{
	node->argc = argc;
	node->argm_cmd1 = ft_split(argv[3], ' ');
	node->argm_cmd2 = ft_split(argv[4], ' ');
	node->argv = argv;
	node->envp = envp;
	node->heredoc_name = argv[2];
	node->loop = -1;
	node->result_of_cmd = -1;
	node->origin_path = ft_take_path(envp);
	node->all_path = ft_split(node->origin_path, ':');
}
