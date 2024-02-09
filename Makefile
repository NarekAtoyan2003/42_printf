# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naatoyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 19:58:56 by naatoyan          #+#    #+#              #
#    Updated: 2024/02/09 18:41:03 by naatoyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
AR_FLAGS = ar rcs
RM_F = rm -f
SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	 $(AR_FLAGS) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM_F) $(OBJ)

fclean : clean
	$(RM_F) $(NAME)

re : fclean all

.PHONY: all clean fclean re
