# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdelou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 17:51:35 by mabdelou          #+#    #+#              #
#    Updated: 2022/02/15 17:51:41 by mabdelou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
NAME = pipex
FILES = ./pipex_mondatory/main.c \
        ./pipex_mondatory/ft_commands.c \
        ./pipex_mondatory/ft_split.c \
		./pipex_mondatory/ft_strjoin.c \
		./pipex_mondatory/ft_strlen.c \
		./pipex_mondatory/take_path.c \

B_FILES = ./pipex_bonus/main.c \
        ./pipex_bonus/ft_commands.c \
        ./pipex_bonus/ft_split.c \
		./pipex_bonus/ft_strjoin.c \
		./pipex_bonus/ft_strlen.c \
		./pipex_bonus/take_path.c \
		./pipex_bonus/heredoc.c \
		./pipex_bonus/ft_strncmp.c \
		./pipex_bonus/ft_putstr_fd.c \
		./pipex_bonus/fill_node.c \
		./pipex_bonus/do_some_malloc.c \
		./pipex_bonus/make_pipes.c \
		./pipex_bonus/multi_pipe.c \
		./pipex_bonus/save_cmds.c \
		./pipex_bonus/close_fds.c \
		./pipex_bonus/get_next_line/get_next_line.c \
		./pipex_bonus/get_next_line/get_next_line_utils.c \

all:  $(NAME)

bonus:
	$(CC) $(B_FILES) -o $(NAME)

$(NAME): $(FILES)
	$(CC) $(FILES) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re bonus
