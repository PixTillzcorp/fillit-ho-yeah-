# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 17:30:28 by heinfalt          #+#    #+#              #
#    Updated: 2016/11/28 17:30:29 by heinfalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re

.SUFFIXES:

NAME = fillit

CC = gcc

SRC = fillit.c

CFLAGS = -Wall -Wextra -Werror

all: $(NAME) fillit.h

$(NAME): $(SRC)
	$(CC) -o $(NAME) $(SRC)

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all