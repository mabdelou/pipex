/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:30:51 by mabdelou          #+#    #+#             */
/*   Updated: 2022/04/05 00:09:21 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/header_bonus.h"
#include "../../lib/get_next_line.h"

void	ft_drr(t_node *node)
{
	node->pid = fork();
	if (node->pid == -1)
		return ;
	if (node->pid == 0)
		ft_cmd1(node, node->argv, node->envp);
	if (fork() == 0)
		ft_cmd2(node, node->argv, node->envp);
	else
	{
		close_fd(node);
		wait(NULL);
		wait(NULL);
	}
}

int	ft_make_some_pipe(t_node *node)
{
	if (pipe(&node->fd[0]) == -1)
		return (1);
	if (pipe(&node->fd[2]) == -1)
		return (1);
	return (0);
}

void	ft_check_if_argumment_is_correct(t_node *node)
{
	if (node->argc > 6)
	{
		write(1, "error use 6 argumment\n", 22);
		exit(0);
	}
}

int	ft_heredoc(t_node *node)
{
	if (ft_make_some_pipe(node))
		return (1);
	ft_check_if_argumment_is_correct(node);
	while (true)
	{
		write(1, "heredoc> ", 10);
		node->ptr = get_next_line(0);
		node->difirent = ft_strncmp(node->ptr, node->heredoc_name);
		if (!node->difirent)
		{
			free(node->ptr);
			break ;
		}
		else
		{
			ft_putstr_fd(node->ptr, node->fd[1]);
			free(node->ptr);
		}
	}
	ft_drr(node);
	return (1);
}
