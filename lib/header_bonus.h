/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:40:38 by mabdelou          #+#    #+#             */
/*   Updated: 2022/02/15 16:40:40 by mabdelou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int		file1;
	int		file2;
	int		fd[4];
	int		*fds;
	int		loop;
	int		pid;
	int		argc;
	int		a;
	int		b;
	int		c;
	int		difirent;
	int		result_of_cmd;
	char	**argv;
	char	**envp;
	char	*ptr;
	char	*origin_path;
	char	**all_path;
	char	**argm_cmd1;
	char	**argm_cmd2;
	char	***arg_cmds;
	char	*heredoc_name;

}	t_node;

char	**ft_split(char const *s, char c);
char	*ft_take_path(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_cmd1(t_node *node, char **argv, char **envp);
void	ft_cmd2(t_node *node, char **argv, char **envp);
void	ft_cmd7(t_node *node, char **argv, char **envp);
void	ft_cmd8(t_node *node, char **argv, char **envp);
void	ft_cmd9(t_node *node, char **argv, char **envp);
void	fill_node(t_node *node, char **argv, char **envp, int argc);
void	ft_argumment_error(int argc);
void	ft_putstr_fd(char *s, int fd);
int		ft_heredoc(t_node *node);
int		ft_strncmp(const char	*s1,	const char	*s2);
void	ft_do_some_malloc(t_node *node);
int		make_pipes(t_node *node);
void	save_cmds(t_node *node);
void	close_fds(t_node *node);
void	close_fd(t_node *node);
void	multi_pipe(t_node *node);

#endif
