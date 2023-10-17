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

#include "../../lib/header.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	node;

	ft_argumment_error(argc);
	node.argm_cmd1 = ft_split(argv[2], ' ');
	node.argm_cmd2 = ft_split(argv[3], ' ');
	node.loop = -1;
	node.result_of_cmd = -1;
	node.origin_path = ft_take_path(envp);
	node.all_path = ft_split(node.origin_path, ':');
	if (pipe(node.fd) == -1)
		return (1);
	node.pid = fork();
	if (node.pid == -1)
		return (1);
	if (node.pid == 0)
		ft_cmd1(&node, argv, envp);
	if (fork() == 0)
		ft_cmd2(&node, argv, envp);
	else
	{
		wait(NULL);
		close(node.fd[1]);
		close(node.fd[0]);
		wait(NULL);
	}
}
