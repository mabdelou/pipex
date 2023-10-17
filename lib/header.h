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

typedef struct s_node
{
	int		file1;
	int		file2;
	int		fd[2];
	int		loop;
	int		pid;
	int		result_of_cmd;
	char	*origin_path;
	char	**all_path;
	char	**argm_cmd1;
	char	**argm_cmd2;

}	t_node;

char	**ft_split(char const *s, char c);
char	*ft_take_path(char **envp);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
void	ft_cmd1(t_node *node, char **argv, char **envp);
void	ft_cmd2(t_node *node, char **argv, char **envp);
void	ft_argumment_error(int argc);

#endif
