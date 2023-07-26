/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:43:34 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/15 16:43:37 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	node;

	ft_argumment_error(argc);
	fill_node(&node, argv, envp, argc);
	if (!ft_strncmp("here_doc", argv[1]))
		if (ft_heredoc(&node))
			return (0);
	ft_do_some_malloc(&node);
	if (make_pipes(&node))
		return (1);
	save_cmds(&node);
	multi_pipe(&node);
	return (0);
}
