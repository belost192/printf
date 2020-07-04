# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chnikia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/28 13:40:29 by chnikia           #+#    #+#              #
#    Updated: 2020/07/04 21:09:18 by chnikia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEAD = ./includes/ft_printf.h
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = sources/ft_what_is_it.c \
		sources/ft_printf.c\
		sources/ft_view_int.c\
		sources/ft_view_str.c\
		sources/ft_view_char.c\
		sources/ft_putchar.c\
		sources/ft_putstr.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror
ARRC = ar rcs
REMF = rm -rf

%.o : %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	$(ARRC) $(NAME) $(OBJS)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(REMF) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(REMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
