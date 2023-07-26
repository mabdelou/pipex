/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:45:19 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/15 17:45:20 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_argumment_error(int argc)
{
	if (argc != 5)
	{
		write(1, "too many argumment\n", 20);
		exit(1);
	}
}

void	ft_cmd1(t_node *node, char **argv, char **envp)
{
	node->file1 = open(argv[1], O_RDONLY);
	if (node->file1 == -1)
	{
		perror("ERROR ON READ FILE");
		exit(1);
	}
	close(node->fd[0]);
	node->loop = -1;
	dup2(node->file1, 0);
	dup2(node->fd[1], 1);
	close(node->fd[0]);
	close(node->file1);
	close(node->fd[1]);
	while (node->result_of_cmd == -1 && node->all_path[node->loop])
		node->result_of_cmd = execve(ft_strjoin(node->all_path[++node->loop],
					node->argm_cmd1[0]), node->argm_cmd1, envp);
	write(2, "command not found:\n", 19);
	exit(1);
}

void	ft_cmd2(t_node *node, char **argv, char **envp)
{
	node->file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	node->loop = -1;
	dup2(node->fd[0], 0);
	dup2(node->file2, 1);
	close(node->fd[1]);
	close(node->fd[0]);
	close(node->file2);
	while (node->result_of_cmd == -1 && node->all_path[node->loop])
		node->result_of_cmd = execve(ft_strjoin(node->all_path[++node->loop],
					node->argm_cmd2[0]), node->argm_cmd2, envp);
	write(2, "command not found:\n", 19);
	exit(1);
}
